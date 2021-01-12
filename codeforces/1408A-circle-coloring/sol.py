from functools import lru_cache
T = int(input())
for _ in range(T):
	N = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	c = list(map(int, input().split()))
	ans = [a[0]]
	for i in range(1, N):
		s = {ans[-1], ans[0]}
		if a[i] not in s:
			ans.append(a[i])
		elif b[i] not in s:
			ans.append(b[i])
		else:
			ans.append(c[i])
	print(' '.join(map(str, ans)))
