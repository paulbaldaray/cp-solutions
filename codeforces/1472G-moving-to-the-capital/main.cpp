#include <iostream>
#include <vector>
#include <functional>
#include <array>
void solve() {
	int N, M, INF = 1e9;
	std::cin >> N >> M;
	std::vector<std::vector<int>> adj(N+1); // 1-index
	for (int i = 0, u, v; i < M; ++i) {
		std::cin >> u >> v;
		adj[u].push_back(v);
	}
	std::vector<int> dist(N+1, -1), level(1, 1);
	for (int d = 0; !level.empty(); ++d) {
		std::vector<int> next_level;
		for (int u : level) {
			if (dist[u] != -1)
				continue;
			dist[u] = d;
			for (int v : adj[u])
				next_level.push_back(v);
		}
		std::swap(level, next_level);
	}
	std::vector<std::array<int, 2>> memo(N+1, {INF, INF});
	std::function<int (int, int)> dp = [&](int u, int k) {
		if (u == 1)
			return 0;
		if (memo[u][k] == INF) {
			memo[u][k] = dist[u];
			for (int v : adj[u]) {
				if (dist[u] < dist[v]) {
					if (k == 0)
						memo[u][k] = std::min(memo[u][k], dp(v, 0));
					else
						memo[u][k] = std::min(memo[u][k], dp(v, 1));
				} else if (k == 1) {
					memo[u][k] = std::min(memo[u][k], dp(v, 0));
				}
			}
		}
		return memo[u][k];
	};
	for (int i = 1; i <= N; ++i)
		std::cout << std::min(dp(i, 0), dp(i, 1)) << ' ';
	std::cout << '\n';
}

int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
		solve();
}
