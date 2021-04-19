#!/bin/python3
import random, os
err_file = open('./fuck', 'w')
def printf(x):
	err_file.write(f'{x}\n')
	err_file.flush()
T, N, Q = 1, 50, 200
nums = random.sample(range(1, N+1), N)
index = {x : i for i, x in enumerate(nums)}
ans = tuple(sorted(nums, key=lambda x : index[x]))
print(T, N, Q, flush=True)
while True:
	l = list(map(int, input().split()))
	if len(l) == N:
		res = 1 if tuple(l) == ans or tuple(l[::-1]) == ans else -1
		print(res, flush=True)
		printf(f'ans: {nums}')
		os._exit(int(res == -1))
	if Q == 0:
		print(-1, flush=True)
		os._exit(1)
	try:
		print(sorted(l, key=lambda x : index[x])[1])
	except KeyError:
		print(-1, flush=True)
		os._exit(1)
	Q -= 1
