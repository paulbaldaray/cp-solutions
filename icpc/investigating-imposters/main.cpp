#include <iostream>
#include <vector>
#include <functional>
#include <unordered_set>
#include <unordered_map>
std::vector<std::vector<int>> tarjanSCC(std::vector<std::vector<int>> &adj) {
	int n = adj.size(), clock = 0;
	std::vector<int> low(n,0), dis(n,0); // 'dis'covery time and 'low'est node reachable
	std::vector<int> has(n,0), stk; // 'has' checks if 'stk' has a node
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
	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> adj(n);
	for (int u = 0, x; u < n; ++u) {
		std::cin >> x;
		for (int i = 0, v; i < x; ++i) {
			std::cin >> v, --v;
			if (u != v)
				adj[u].push_back(v);
		}
	}
	auto sccs = tarjanSCC(adj);
	std::unordered_map<int, int> family;
	for (int i = 0; i < sccs.size(); ++i)
		for (int u : sccs[i])
			family[u] = i;

	std::vector<std::unordered_set<int>> scc_radj(n);
	for (int i = 0; i < sccs.size(); ++i)
		for (auto u : sccs[i])
			for (int v : adj[u])
				scc_radj[family[v]].insert(i);

	std::unordered_map<int, int> memo;
	std::function<int (int)> dp = [&](int u) {
		if (memo.count(u))
			return memo[u];
		int ans = sccs[u].size();
		for (int v : scc_radj[u])
			if (v != u)
				ans += dp(v);
		return memo[u] = ans;
	};

	std::vector<bool> ans(n, false);
	for (int i = 0; i < sccs.size(); ++i)
		if (dp(i) > k)
			for (int u : sccs[i])
				ans[u] = true;

	for (int i = 0; i < n; ++i)
		std::cout << ans[i] << '\n';
}
