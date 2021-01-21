#include <iostream>
#include <vector>
std::vector<int> distance;
std::vector<std::vector<int>> adj;
void solve() {
	int N, M;
	std::cin >> N >> M;
	distance.assign(N, N);
	adj.assign(N, {});
	for (int i = 0, u, v; i < M; ++i) {
		std::cin >> u >> v;
		adj[i].push_back(u);
	}
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
		solve();
}
