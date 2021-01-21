#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long LL;
int N;
vector<vector<int>> adj;
unordered_set<int> vis;
vector<vector<int>> cmps;
int dfs(int u) {
	vis.insert(u);
	int nodes = 0;
	for (int v : adj[u])
		if (!vis.count(v)) {
			int x = dfs(v);
			cmps[u].push_back(x);
			nodes += x;
		}
	if (N - nodes - 1)
		cmps[u].push_back(N - nodes - 1);
	return nodes + 1;
}
int main() {
	cin >> N;
	adj.resize(++N);
	cmps.resize(N);
	for (int i = 0; i < N-1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	LL worst = 0, best = 0;
	for (int u = 0; u < N; ++u) {
		LL nodes = 0, uworst = 0;
		for (LL v : cmps[u])
			uworst += v * nodes, nodes += v;
		if (uworst > worst) {
			worst = uworst;
			sort(cmps[u].begin(), cmps[u].end());
			LL x = cmps[u].back();
			cmps[u].pop_back();
			if (cmps[u].empty())
				continue;
			cmps[u].back() += x;
			nodes = 0, uworst = 0;
			for (LL v : cmps[u])
				uworst += v * nodes, nodes += v;
			best = uworst;
		}
	}
	cout << worst << " " << best;
}
