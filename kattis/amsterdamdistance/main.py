from math import pi
M, N, R = input().split()
M = int(M)
N = int(N)
R = float(R)
ax, ay, bx, by = map(int, input().split())
ans = 0.0
if by > ay:
	ax, ay, bx, by = bx, by, ax, ay
ans += abs(ay-by)*(1/N)*R
angle = abs(ax-bx)*(pi/M)
ans += min(2,angle)*by*(1/N)*R
print(ans)
