from functools import lru_cache
from math import inf
N, M, K = map(int, input().split())
trees = [0] + list(map(int, input().split()))
costs = [0]*(N+1)
for i in range(1, N+1):
	costs[i] = [0] + list(map(int, input().split()))
@lru_cache(None)
def dp(i, j, k):
	if i == N+1 and k == K:
		return 0
	if i == N+1:
		return inf
	if trees[i] != 0:
		return dp(i+1, trees[i], k+(trees[i]!=j))
	ans = inf
	for c in range(1, M+1):
		ans = min(ans, dp(i+1, c, k+int(c!=j)) + costs[i][c])
	return ans
print(dp(1, 0, 0) if dp(1, 0, 0) != inf else -1)
