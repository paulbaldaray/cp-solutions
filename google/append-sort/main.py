import math
def append(x, y): # x < y
	if x > y:
		return x
	sx, sy = str(x), str(y)
	head, tail = sy[:len(sx)], sy[len(sx):]
	if x > int(head):
		return int(sx+'0'*(len(sy)-len(sx)))
	elif x == int(head):
		end = 0
		while tail and tail[-1] == '9':
			end += 1
			tail = tail[:-1]
		if tail:
			return int(sx + str(tail[:-1])+str(int(tail[-1])+1)+'0'*end)
	nx = int(sx+'0'*(len(sy)-len(sx)+1))
	return nx

def solve():
	n, nums = int(input()), list(map(int, input().split()))
	ans = []
	for x in nums:
		ans.append(append(x, ans[-1] if ans else -math.inf))
	cost = 0
	for x, y in zip(nums, ans):
		cost += len(str(y))-len(str(x))
	return cost

if __name__ == '__main__':
	for t in range(int(input())):
		print(f'Case #{t+1}: {solve()}')
