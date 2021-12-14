#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <set>
#include <map>
using LL = long long;
using PLL = std::pair<LL, LL>;
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(NULL);
	LL n, m, x, y;
	std::cin >> n >> m >> x >> y;

	std::vector<std::vector<PLL>> adj(n+1);
	for (LL i = 0, u, v, w; i < m; ++i) {
		std::cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	std::vector<LL> thresh(n+1), cost(n+1);
	for (LL i = 1; i <= n; ++i)
		std::cin >> thresh[i] >> cost[i];

	std::vector<std::map<LL, LL>> dist(n+1);
	for (LL r = 1; r <= n; ++r) {
		std::priority_queue<PLL, std::vector<PLL>, std::greater<PLL>> pq;
		pq.push({0, r});
		while (!pq.empty()) {
			auto [d, u] = pq.top(); pq.pop();
			if (dist[r].count(u))
				continue;
			dist[r][u] = d;
			for (auto [v, w] : adj[u])
				pq.push({d + w, v});
		}
	}
	
	LL ans = -1;
	std::set<LL> vis;
	std::priority_queue<PLL, std::vector<PLL>, std::greater<PLL>> pq;
	pq.push({0, x});
	while (!pq.empty()) {
		auto [c, u] = pq.top(); pq.pop();
		if (u == y) {
			ans = c;
			break;
		}
		if (vis.count(u))
			continue;
		vis.insert(u);
		for (auto [v, w] : dist[u])
			if (w <= thresh[u])
				pq.push({c + cost[u], v});
	}
	std::cout << ans << '\n';
}
