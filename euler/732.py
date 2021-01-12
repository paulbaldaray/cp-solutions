def r():
	curr = 1
	n = 0
	while True:
		curr = (pow(5, n, 10**9 + 7) % 101) + 50
		yield curr
		n += 1

def create_trolls(N):
	# height, length, iq
	trolls = []
	gen = iter(r())
	for i in range(N):
		trolls.append( (next(gen), next(gen), next(gen)) )
	return trolls, sum(t[0] for t in trolls) / (2**.5)

import sys, os, time
sys.setrecursionlimit(10000)
from functools import lru_cache
def solve_trolls(trolls, hole_height):
	trolls.sort(key = lambda x : x[0]+x[1])
	h, l, q = map(list, zip(*trolls))
	@lru_cache(None)
	def solve(i, height):
		if i == len(trolls):
			return 0
		stay = solve(i+1, height)
		if height+l[i] < hole_height:
			return stay
		escape = q[i] + solve(i+1, height-h[i])
		return max(escape, stay)
	return solve(0, sum(h))

if __name__ == '__main__':
	if len(sys.argv) <= 1:
		os._exit(0)
	trolls, hole_height = create_trolls(int(sys.argv[1]))
	start = time.time()
	print(solve_trolls(trolls, hole_height))
	print(f'Time: {time.time() - start}')	
