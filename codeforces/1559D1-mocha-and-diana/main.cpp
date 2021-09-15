#include <iostream>
#include <vector>
int find(int u, std::vector<int>& p) {
	return p[u] < 0 ? u : p[u] = find(p[u], p);
}

bool uni(int u, int v, std::vector<int>& p, bool test = false) {
	int pu = find(u, p), pv = find(v, p);
	if (test || pu == pv)
		return pu == pv;
	if (p[pu] > p[pv])
		std::swap(pu, pv);
	p[pu] += p[pv];
	p[pv] = pu;
	return false;
}

int main() {
	int n, m1, m2, u, v;
	std::cin >> n >> m1 >> m2;
	std::vector<int> p1(n+1, -1), p2(n+1, -1);

	while (m1--)
		std::cin >> u >> v, uni(u, v, p1);
	while (m2--)
		std::cin >> u >> v, uni(u, v, p2);

	std::vector<std::pair<int, int>> ans;
	for (int u = 1; u <= n; ++u)
		for (int v = u+1; v <= n; ++v)
			if (!uni(u, v, p1, true) && !uni(u, v, p2, true))
				uni(u, v, p1), uni(u, v, p2), ans.push_back({u, v});

	std::cout << ans.size() << '\n';
	for (auto [u, v] : ans)
		std::cout << u << " " << v << '\n';
}
