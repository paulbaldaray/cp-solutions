x, y = map(int, input().split())
n = int(input())
for i in range(n):
	l, u, f = input().split()
	l, u, f = int(l), int(u), float(f)
	y += (u-l)*f - (u-l)
print(x/y)
