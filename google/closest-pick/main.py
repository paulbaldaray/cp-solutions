def dist(lo, hi, K):
	assert(hi == -1 or lo < hi)
	flag = False
	if lo == -1:
		flag = True
		lo = 0
	if hi == -1:
		flag = True
		hi = K+1
	tot = (hi - lo - 1)
	if not flag:
		tot //= 2
	return tot+1

def solve():
	N, K = map(int, input().split())
	nums = set(map(int, input().split()))
	numl = sorted(nums)
	nextlt = {}
	nextgt = {}
	possible = []
	for i, x in enumerate(numl):
		if x-1 not in nums and x > 1:
			possible.append(x-1)
			nextlt[x-1] = numl[i-1] if i else -1
			nextgt[x-1] = x
		if x+1 not in nums and x < K:
			possible.append(x+1)
			nextgt[x+1] = numl[i+1] if i+1 < len(numl) else -1
			nextlt[x+1] = x
	possible = sorted(set(possible))
	ans = 0
	for i in range(len(possible)):
		for j in range(i+1, len(possible)):
			ix, jx = possible[i], possible[j]
			for iafter in [False, True]:
				for jafter in [False, True]:
					if iafter and not jafter and nextgt[ix] == nextgt[jx]:
						ans = max(ans, jx-ix+1)
						continue
					curr = 0
					if iafter:
						curr += dist(ix, nextgt[ix], K)
					else:
						curr += dist(nextlt[ix], ix, K)
					if jafter:
						curr += dist(jx, nextgt[jx], K)
					else:
						curr += dist(nextlt[jx], jx, K)
					ans = max(ans, curr)
	for i in range(len(possible)):
		ix = possible[i]
		for iafter in [False, True]:
			curr = 0
			if iafter:
				curr += dist(ix, nextgt[ix], K)
			else:
				curr += dist(nextlt[ix], ix, K)
			ans = max(ans, curr)
	return ans/K

if __name__ == '__main__':
	T = int(input())
	for t in range(T):
		print(f'Case #{t+1}: {solve()}')
