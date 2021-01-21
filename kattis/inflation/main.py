import math
n = int(input())
l = list(map(int, input().split()))
l.sort()
ans = math.inf
high = 0
for i,x in enumerate(l):
	cap = x/(i+1)
	ans = min(ans, cap)
	high = max(high, cap)
if high > 1.0:
	print('impossible')
else:
	print(ans)
