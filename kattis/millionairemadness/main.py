import heapq, math
M, N = map(int, input().split())
heights = [list(map(int, input().split()))for _ in range(M)]
visited = set()
distances = {}
pq = []
pq.append( (0,0,0) )
heapq.heapify(pq)

dirs = [(0, 1),(1,0),(0,-1),(-1,0)]
while pq:
	d, row, col = heapq.heappop(pq)
	if (row, col) in visited:
		continue
	visited.add( (row,col) )
	if (row, col) in distances and distances[(row,col)] <= d:
		continue
	if row == M-1 and col == N-1:
		print(d)
		break
	for dr, dc in dirs:
		if not ((-1 < row+dr < M)\
				and (-1 < col+dc < N)\
				and ((row+dr,col+dc) not in visited)):
			continue
		diff = max(0, heights[row+dr][col+dc]-heights[row][col])
		heapq.heappush(pq, (max(d, diff), row+dr, col+dc))
