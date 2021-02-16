#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
typedef long long LL;
LL N, M;
std::vector<std::array<int, 3>> edges; // (w, u, v)
std::vector<std::vector<std::array<int, 2>>> adj; // u->(v, w)
std::vector<LL> parent, binary;
int find(int u) {
	return u == parent[u] ? u : parent[u] = find(parent[u]);
}
bool uni(int u, int v) {
	if (find(u) == find(v))
		return false;
	parent[find(u)] = find(v);
	return true;
}
int dfs(int u, int p) {
	int total_cmp = 1;
	for (auto &e : adj[u]) if (e[0] != p) {
		LL cmp = dfs(e[0], u);
		binary[e[1]] = (N - cmp) * cmp;
		total_cmp += cmp;
	}
	return total_cmp;
}
int main() {
	std::cin >> N >> M;
	edges.assign(M, {});
	for (int i = 0; i < M; ++i) {
		std::cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
		--edges[i][1], --edges[i][2]; // 0-index
	}
	std::sort(edges.begin(), edges.end());
	for (int i = 0; i < N; ++i)
		parent.push_back(i);
	adj.assign(N, {});
	int max_bin = 1;
	for (int i = 0; i < M; ++i) {
		auto &e = edges[i];
		if (uni(e[1], e[2])) {
			adj[e[1]].push_back({e[2], e[0]});
			adj[e[2]].push_back({e[1], e[0]});
			max_bin = std::max(max_bin, e[0]);
		}
	}
	binary.assign(max_bin+1, 0);
	dfs(0, -1);
	std::string ans;
	for (LL i = 0, rem = 0; rem || i < binary.size(); ++i) {
		rem += i < binary.size() ? binary[i] : 0;
		ans += '0' + (rem % 2), rem /= 2;
	}
	std::reverse(ans.begin(), ans.end());
	std::cout << ans << '\n';
}
