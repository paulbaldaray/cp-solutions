from collections import defaultdict
def primeCounts(x):
	p = 2
	pcount = defaultdict(int)
	while p*p <= x:
		if x % p == 0:
			x //= p
			pcount[p] += 1
		else:
			p += 1
	if x > 1:
		pcount[x] += 1
	return pcount


def solve():
	cards = defaultdict(int)
	for i in range(int(input())):
		p, c = map(int, input().split())
		cards[p] += c
	lcards = list(cards.items())
	high = 0
	for p, c in lcards:
		high += p*c
		
	vis = set()
	def products(x, current):
		if x == len(lcards):
			return
		products(x+1, current)
		for i in range(lcards[x][1]):
			current *= lcards[x][0]
			if current > high:
				break
			vis.add(current)
			products(x+1, current)
	products(0, 1)

	for ans in sorted(vis, reverse=True):
		factors = primeCounts(ans)
		val = 0
		for p in cards:
			val += (cards[p]-factors[p])*p
		if val == ans:
			return ans
	return 0

if __name__ == '__main__':
	for t in range(int(input())):
		print(f'Case #{t+1}: {solve()}')
