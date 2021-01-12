n, k = map(int, input().split())
ans = []
for i in range(n):
	ans.append([c for c in input()])
for i in range(1, k):
	arr = [list(x) for x in ans]
	ans = [['*']*(n**(i+1)) for x in range(n**(i+1))]
	nx = n**i
	for r in range(nx):
		for c in range(nx):
			x = arr[r][c]
			for rx in range(n):
				for cx in range(n):
					ans[r*n+rx][c*n+cx] = '*' if x == '*' else arr[rx][cx]
for row in ans:
	print(''.join(row))
