N, M = map(int, input().split())
C = list(map(int, input().split()))
total = sum(C)

assert(1 <= N <= 10**5)
assert(1 <= M <= 2*10**9)
assert(len(C) == N)
assert(all(1 <= x <= 10**9 for x in C))
assert(0 <= sum(C) <= 2*10**9)

ans = (M//total) * N
M %= total
for x in C:
	if M < x:
		break
	ans += 1
	M -= x
print(ans)
