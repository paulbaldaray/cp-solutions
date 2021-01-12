from math import ceil, sqrt
total = 0
visited = set()
for i in range(2, 2*10**6):
	if i not in visited:
		for j in range(i, 2*10**6, i):
			visited.add(j)
		total += i
print(total)
