from random import choice, randrange, shuffle
from string import ascii_lowercase as letters
N = 1000
Q = 1000
letters = list(letters)
print(N, Q)
for n in range(N):
	print(''.join([choice(letters) for x in range(randrange(1, 50))]))
for q in range(Q):
	K = randrange(1, N+1)
	L = randrange(1, K+1)
	print(K, L)
	nums = [i for i in range(1, N+1)]
	chosen = set()
	shuffle(nums)
	for i in range(K):
		for j in nums:
			if j not in chosen:
				break
		chosen.add(j)
		print(f'{j}{" " if i != K-1 else ""}', end="")
	print()
