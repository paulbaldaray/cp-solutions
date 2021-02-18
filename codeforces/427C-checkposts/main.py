def tarjanSCC(adj: [[int]]):
	n, clock = len(adj), iter(range(1, len(adj)+1))
	dis, low = [0]*n, [0]*n # 'dis'covery time and 'low'est node reachable
	has, stk = [0]*n, [] # 'has' checks if a node is on the DFS 'stk'
	sccs: [[int]] = [] # holds a list of sccs with their nodes
	def dfs(u: int):
		dis[u] = low[u] = next(clock)
		stk.append(u)
		has[u] = True
		for v in adj[u]:
			if not dis[v]:
				dfs(v)
			if has[v]: # on the stack means found lower
				low[u] = min(low[u], low[v])
		if low[u] == dis[u]: # did not find lower
			sccs.append([])
			while True:
				v = stk.pop()
				has[v] = False;
				sccs[-1].append(v)
				if v == u:
					break
	for u in range(n):
		if not dis[u]:
			dfs(u)
	return sccs

n = int(input())
cost = list(map(int, input().split()))
adj = [[] for _ in range(n)]
m = int(input())
for _ in range(m):
	u, v = map(int, input().split())
	adj[u-1].append(v-1)
sccs = tarjanSCC(adj)
ans, ways, mod = 0, 1, 10**9+7
for scc in sccs:
	min_elem, total = cost[scc[0]], 0
	for u in scc:
		min_elem = min(min_elem, cost[u])
	for u in scc:
		if cost[u] == min_elem:
			total += 1
	ans += min_elem
	ways = (ways*total) % mod
print(ans, ways)
