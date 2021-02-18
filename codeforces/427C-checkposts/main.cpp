#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
typedef long long LL;
std::vector<std::vector<int>> tarjanSCC(std::vector<std::vector<int>> &adj) {
	int n = adj.size(), clock = 0;
	std::vector<int> low(n), dis(n); // 'dis'covery time and 'low'est node reachable
	std::vector<int> has(n), stk; // 'has' checks if 'stk' has a node
	std::vector<std::vector<int>> sccs; // holds a list of sccs with their nodes
	std::function<void (int)> dfs = [&](int u) {
		dis[u] = low[u] = ++clock;
		stk.push_back(u);
		has[u] = true;
		for (int v : adj[u]) {
			if (!dis[v])
				dfs(v);
			if (has[v]) // On the stack means found lower
				low[u] = std::min(low[u], low[v]);
		}
		if (low[u] == dis[u]) { // No path to low nodes, so it's the cutoff for an SCC
			sccs.push_back({});
			while (true) {
				int v = stk.back();
				stk.pop_back();
				has[v] = false;
				sccs.back().push_back(v);
				if (u == v)
					break;
			}
		}
	};
	for (int u = 0; u < adj.size(); ++u) // assumes zero indexed
		if (!dis[u])
			dfs(u);
	return sccs;
}
int main() {
	int n, m;
	std::cin >> n;
	std::vector<int> cost(n);
	for (int i = 0; i < n; ++i)
		std::cin >> cost[i];
	std::cin >> m;
	std::vector<std::vector<int>> adj(n);
	for (int i = 0, u, v; i < m; ++i)
		std::cin >> u >> v, adj[u-1].push_back(v-1);
	auto sccs = tarjanSCC(adj);
	LL ans = 0, ways = 1, mod = 1e9+7;
	for (auto &scc : sccs) {
		int min_cost = cost[scc[0]], total = 0;
		for (int u : scc)
			min_cost = std::min(min_cost, cost[u]);
		for (int u : scc)
			if (cost[u] == min_cost)
				++total;
		ans += min_cost;
		ways = (ways*total) % mod;
	}
	std::cout << ans << ' ' << ways << '\n';
}
