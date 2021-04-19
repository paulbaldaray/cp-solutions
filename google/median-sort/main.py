#!/bin/python3
import random, time, os
def median(a, b, c):
	print(' '.join(map(str, (a, b, c))), flush=True)
	m = int(input())
	assert(m != -1)
	return m

def tsort(nums, lt=0, gt=0) -> [int]:
	if len(nums) <= 1:
		return nums
	l, r = nums.pop(), nums.pop()
	if (lt and median(l, r, lt) == r) or (gt and median(l, r, gt) == l):
		l, r = r, l
	left, middle, right = [], [], []
	for x in nums:
		m = median(l, x, r)
		bucket = left if l == m else (middle if x == m else right)
		bucket.append(x)
	return tsort(left, 0, l) + [l] + tsort(middle, l) + [r] + tsort(right, l)

if __name__ == '__main__':
	random.seed(time.time()+42069)
	T, N, Q = map(int, input().split())
	for t in range(T):
		nums = random.sample(range(1, N+1), N)
		tsortnums = tsort(nums)
		print(' '.join(map(str, tsortnums)), flush=True)
		assert(int(input()) != -1)
