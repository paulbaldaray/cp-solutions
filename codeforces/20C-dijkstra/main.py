from heapq import heappush as push, heappop as pop
from collections import defaultdict

N, M = map(int, input().split())
adj = defaultdict(lambda: defaultdict(lambda: 10**8))
for _ in range(M):
	u, v, w = map(int, input().split())
	adj[u-1][v-1] = min(adj[u-1][v-1], w)
	adj[v-1][u-1] = min(adj[u-1][v-1], w)

pq = []
backptr = [-1] * N
visited = set()
push(pq, (0, 0, -1))
while pq:
	d, u, p = pop(pq)
	if u in visited:
		continue
	visited.add(u)
	backptr[u] = p
	for v in adj[u]:
		push(pq, (d+adj[u][v], v, u))

if backptr[N-1] == -1:
	print(-1)
else:
	node = N-1
	path = []
	while node != -1:
		path.append(str(node+1))
		node = backptr[node]
	print(' '.join(path[::-1]))
