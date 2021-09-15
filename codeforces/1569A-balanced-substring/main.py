def solve():
	n = int(input())
	l = input()
	d = {0:0}
	total = 0
	for i, x in enumerate(l):
		if x == 'a':
			total += 1
		else:
			total -= 1
		if total in d:
			return f'{d[total]+1} {i+1}'
		d[total] = i+1
	return '-1 -1'

for i in range(int(input())):
	print(solve())
