#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;
#define F first
#define S second
typedef pair<int, int> ii;
int main() {
	int N, M;
	cin >> N >> M;
	int sx, sy, fx, fy;
	cin >> sx >> sy >> fx >> fy;
	vector<ii> xs;
	vector<ii> ys;
	vector<unordered_map<int, int>> adj(M+2);
	adj[0][M+1] = abs(sx - fx) + abs(sy - fy);
	for (int m = 1; m <= M; ++m) {
		int x, y;
		cin >> x >> y;
		xs.emplace_back(x, m);
		ys.emplace_back(y, m);
		adj[0][m] = min(abs(sx - x), abs(sy - y));
		adj[m][M+1] = abs(fx - x) + abs(fy - y);
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	for (int i = 1; i < xs.size(); ++i) {
		int x1 = xs[i-1].F, x2 = xs[i].F, xm1 = xs[i].S, xm2 = xs[i-1].S,
				y1 = ys[i-1].F, y2 = ys[i].F, ym1 = ys[i].S, ym2 = ys[i-1].S;
		if (!adj[xm1].count(xm2) || adj[xm1][xm2] > x2 - x1)
			adj[xm1][xm2] = adj[xm2][xm1] = x2 - x1;
		if (!adj[ym1].count(ym2) || adj[ym1][ym2] > y2 - y1)
			adj[ym1][ym2] = adj[ym2][ym1] = y2 - y1;
	}
	vector<int> dist(M+2, INT_MAX);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		int d = pq.top().F, u = pq.top().S;
		pq.pop();
		if (dist[u] <= d)
			continue;
		dist[u] = d;
		if (u == M+1)
			break;
		for (auto &vd : adj[u]) {
			pq.push({vd.S+d, vd.F});
		}
	}
	cout << dist[M+1] << '\n';
}
