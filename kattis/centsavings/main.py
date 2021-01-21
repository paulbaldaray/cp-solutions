from functools import lru_cache
from math import inf
from sys import setrecursionlimit
N, D = map(int, input().split())
L = list(map(int, input().split()))

setrecursionlimit(100000)

def rnd(val):
	x = val % 10
	val -= x
	return val+10 if x >= 5 else val

@lru_cache(None)
def dp(i, d):
	if i == 0:
		return 0
	nodiv = dp(i-1, d)+L[i-1]
	if d == 0:
		return nodiv
	div = rnd(dp(i-1, d-1)+L[i-1])
	return min(nodiv, div)

ans = inf
for d in range(D+1):
	ans = min(ans, rnd(dp(N, d)))
print(ans)
