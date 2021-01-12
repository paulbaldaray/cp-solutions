from collections import defaultdict
T = int(input())
for _ in range(T):
	N = int(input())
	arr = list(map(int, input().split()))
	d = defaultdict(list)
	for i, x in enumerate(arr):
		d[x].append(i)
	l = sorted(d)
	ans = [-1] * (N+1)
	for x in l:
		ind = d[x]
		space = ind[0]+1
		for i in range(len(ind)-1):
			diff = ind[i+1] - ind[i]
			space = max(space, diff)
		space = max(space, N - ind[-1])
		if ans[space] == -1:
			ans[space] = x
	lo = -1
	for i, x in enumerate(ans):
		if lo == -1 or (x != -1 and x < lo):
			lo = x
		ans[i] = lo
	print(' '.join(map(str, ans[1:])))
