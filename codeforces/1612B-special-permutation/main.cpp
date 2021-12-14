#include <iostream>
#include <vector>
void solve() {
	int n, a, b;
	std::cin >> n >> a >> b;
	std::vector<int> vis(n+1), first{a}, second{b};
	vis[a] = vis[b] = true;
	for (int i = n; first.size() < n/2 && i > a; --i)
		if (!vis[i])
			first.push_back(i), vis[i] = true;
	for (int i = 1; i < b; ++i)
		if (!vis[i])
			second.push_back(i);
	if (first.size() == second.size() && first.size() == n/2) {
		for (int x : first)
			std::cout << x << " ";
		for (int x : second)
			std::cout << x << " ";
		std::cout << '\n';
	} else
		std::cout << -1 << '\n';
}
int main() {
	int T;
	std::cin >> T;
	while (T--)
		solve();
}
