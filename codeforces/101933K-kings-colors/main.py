from math import comb
N, K = map(int, input().split())
ans, sign = 0, 1
for k in range(K, 1, -1):
  ans, sign = (ans + sign*k*(k-1)**(N-1)*comb(K, k)) % (10**9 + 7), -sign
print(ans)
