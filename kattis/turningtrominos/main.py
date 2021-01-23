def solve(x, y):
	s = 4
	while x >= s or y >= s or (x >= s//2 and y >= s//2):
		s *= 2
	if x < s//2 and y < s//2 and (x < s//4 or y < s//4):
		return 0
	elif x < s//2 and y >= s//2 and (x < s//4 or y >= s*3//4):
		return (solve(s-1-y, x)+1)%4
	elif x >= s//2 and y < s//2 and (x >= s*3//4 or y < s//4):
		return (solve(y, s-1-x)+3)%4
	else:
		return solve(x-s//4, y-s//4)
for _ in range(int(input())):
	print(solve(*map(int, input().split())))
