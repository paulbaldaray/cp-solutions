import sys, functools
sys.setrecursionlimit(10**5)
def solve():
	X, Y, S = input().split()
	X, Y = map(int, [X, Y])
	@functools.lru_cache(None)
	def cost(i, p):
		if i == len(S):
			return 0
		if S[i] == 'C':
			return cost(i+1, S[i]) + Y*int(p == 'J')
		if S[i] == 'J':
			return cost(i+1, S[i]) + X*int(p == 'C')
		C = cost(i+1, 'C') + Y*int(p == 'J')
		J = cost(i+1, 'J') + X*int(p == 'C')
		return min(C, J)
	return cost(0, '')

if __name__ == '__main__':
	for t in range(int(input())):
		print(f'Case #{t+1}: {solve()}')
