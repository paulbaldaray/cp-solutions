#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define F first
#define S second
typedef pair<int,int> ii;
typedef pair<ii, int> iii;
int main() {
	int N, M; cin >> N >> M;
	vector<> adj(N);
	while (M--) {
		int u, v, w; cin >> u >> v >> w;
		if (adj[u].count(v)) {
			adj[u-1].insert({w, v-1});
			adj[v-1].insert({w, u-1});
		}
	}
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	vector<int> dist(N, INT_MAX);
	vector<int> backptr(N, -1);
	pq.push({{0, 0}, -1});
	while (!pq.empty()) {
		int d = pq.top().F.F,
				u = pq.top().F.S,
				p = pq.top().S;
		pq.pop();
		if (dist[u] <= d)
			continue;
		dist[u] = d;
		backptr[u] = p;
		if (u == N-1)
			break;
		for (auto wv : adj[u]) if (wv.S != p) {
			int w = wv.F, v = wv.S;
			pq.push({{d+w, v}, u});
		}
	}
	if (backptr[N-1] == -1)
		cout << -1 << '\n';
	else {
		int node = N-1;
		vector<int> path;
		while (node != -1) {
			path.push_back(node+1);
			node = backptr[node];
		}
		for (int i = path.size()-1; i >= 0; --i)
			cout << path[i] << (i ? ' ' : '\n');
	}
}
