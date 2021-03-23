from functools import lru_cache
import sys
sys.setrecursionlimit(1000000)
def solve(N, T):
	binary = []
	while N:
		binary.append(N%2)
		N//=2
	@lru_cache(None)
	def dp(x, b):
		if 2**b*x > 2**(b+2)*T:
			return 0
		if b == -1:
			return 1 if x == 0 else 0
		ans = 0
		for i in range(0, x+1+binary[b]):
			if binary[b]+x-i <= T:
				ans = (ans+dp(i*2, b-1))%998244353
		return ans
	return dp(0, len(binary)-1)

print(solve(*map(int, input().split())))
