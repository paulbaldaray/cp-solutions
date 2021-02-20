import math
T = int(input())
for t in range(T):
	N, M = map(int, input().split())
	cmax = list(map(int, input().split()))
	total = cmax[0]
	for i in range(1, N):
		total += cmax[i]
		cmax[i] = max(total, cmax[i-1])
	for x in map(int, input().split()):
		l, r = 0, 10**15
		while l < r:
			m = (l+r)//2
			srow = m//N*total
			if m < N:
				test = cmax[m] >= x
			elif total <= 0:
				test = cmax[N-1] >= x
			else:
				test = max(srow - total + cmax[N-1], srow + cmax[m%N]) >= x
			if test:
				r = m
			else:
				l = m+1
		print(l if l!=10**15 else -1, end=' ')
	print()
