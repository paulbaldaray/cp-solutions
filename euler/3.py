from math import ceil, sqrt
num = 600851475143
upto = int(sqrt(num))
last = 0
visited = set()
for i in range(2, upto+1):
	if i not in visited and num % i == 0:
		for j in range(i, upto+1, i):
			visited.add(j)
		last = i
print(last)
