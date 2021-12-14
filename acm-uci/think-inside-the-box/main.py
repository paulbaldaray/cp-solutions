N, M = map(int, input().split())
B = sorted(map(int, input().split()))
p = l = 1

for i in range(1, M):
    if B[i] == B[i-1]:
        continue
    l += 1
    if B[i] != B[i-1] + 1:
        p += 1

print(l, p)
