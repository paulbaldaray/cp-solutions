def solve():
	n, k = map(int, input().split())
	arr = list(map(int, input().split()))
	l, r = 0, len(arr)-1
	while l < r and k:
		if arr[l] == 0:
			l += 1
		else:
			arr[l] -= 1
			arr[r] += 1
			k -= 1
	print(' '.join(map(str, arr)))

for i in range(int(input())):
	solve()
