#include <cstdio>
#include <vector>
#include <functional>
int main() {
	int N, M;
	std::scanf("%d %d", &N, &M);
	std::vector<bool> cat(N);
	for (int i = 0, x; i < N; ++i)
		std::scanf("%d", &x), cat[i] = x;
	std::vector<std::vector<int>> adj(N);
	for (int i = 0, u, v; i < N-1; ++i) {
		std::scanf("%d %d", &u, &v);
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	int ans = 0;
	std::function<void (int, int, int, int)> dfs = [&](int u, int p, int cats, int curr) {
		int new_cats = cat[u] ? cat[u] + curr : 0;
		int max_cats = std::max(cats, new_cats);
		if (adj[u].size() == 1 && u != 0) { // if leaf
			ans += (std::max(cats, curr + cat[u]) <= M);
			return;
		}
		for (int v : adj[u])
			if (v != p)
				dfs(v, u, max_cats, new_cats);
	};
	dfs(0, -1, 0, 0);
	std::printf("%d\n", ans);
}
