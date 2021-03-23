#include <vector>
#include <deque>
#include <algorithm>
#include <cstdio>
#include <climits>
typedef long long LL;
struct Dinic {
	struct Edge {
		LL v, c, f, r;
	};
	LL sz, source, sink;
	std::vector<LL> level, eptr;
	std::vector<std::vector<Edge>> adj;

	Dinic(LL n, LL s, LL t) : source{s}, sink{t}, sz{n}, adj(n), level(n), eptr(n) {}

	void addEdge(LL u, LL v, LL c) {
		adj[u].push_back({v, c, 0, (LL)adj[v].size()});
		adj[v].push_back({u, 0, 0, (LL)adj[u].size()-1});
	}

	bool findPaths() {
		std::fill(eptr.begin(), eptr.end(), 0);
		std::fill(level.begin(), level.end(), -1);
		std::deque<LL> q;
		level[source] = 0;
		q.push_back(source);
		while (!q.empty()) {
			LL u = q.front();
			q.pop_front();
			for (Edge &e : adj[u])
				if (level[e.v] == -1 && e.f < e.c)
					level[e.v] = level[u]+1, q.push_back(e.v);
		}
		return level[sink] != -1;
	}

	LL sendFlow(LL u, LL f) {
		if (u == sink)
			return f;
		for (; eptr[u] < adj[u].size(); ++eptr[u]) {
			Edge &e = adj[u][eptr[u]];
			if (level[e.v] == level[u]+1 && e.f < e.c)
				if (LL tmp = sendFlow(e.v, std::min(f, e.c-e.f))) {
					e.f += tmp;
					adj[e.v][e.r].f -= tmp;
					return tmp;
				}
		}
		return 0;
	}

	LL maxFlow(LL startingFlow) {
		if (source == sink)
			return 0;
		LL total = 0;
		while (findPaths())
			while (LL flow = sendFlow(source, startingFlow))
				total += flow;
		return total;
	}

	LL edgesUsed() {
		LL ans = 0;
		for (LL u = 0; u < sz; ++u)
			for (Edge &e : adj[u])
				if (e.f > 0)
					++ans;
		return ans;
	}

	void print() {
		for (LL u = 0; u < sz; ++u)
			for (Edge &e : adj[u])
				if (e.f > 0)
					std::printf("%lld %lld %lld\n", u, e.v, e.f);
	}
};

int main() {
	LL n, m, s, t;
	std::scanf("%lld %lld %lld %lld", &n, &m, &s, &t);
	Dinic graph(n, s, t);
	for (LL i = 0, u, v, c; i < m; ++i) {
		std::scanf("%lld %lld %lld", &u, &v, &c);
		graph.addEdge(u, v, c);
	}
	LL maxFlow = graph.maxFlow(INT_MAX), edgesUsed = graph.edgesUsed();
	std::printf("%lld %lld %lld\n", n, maxFlow, edgesUsed);
	graph.print();
}
