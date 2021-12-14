from random import randrange, shuffle
import math
N = 10**9
M = 10**5
print(N, M)
points = []
branch_side = int(math.log2(M))
branch_dup = int(math.log10(M))
while M > 0:
	num = randrange(N)
	points.append(num)
	M -= 1

	right = randrange(min([M+1, branch_side, N-num]))
	for i in range(num+1, num+right+1):
		points.append(i)
	M -= right

	left = randrange(min([M+1, branch_side, num+1]))
	for i in range(num-1, num-left-1, -1):
		points.append(i)
	M -= left
	

	dups = randrange(min(M+1, branch_dup))
	for _ in range(dups):
		points.append(num)
	M -= dups

shuffle(points)
print(' '.join(map(str, points)))
