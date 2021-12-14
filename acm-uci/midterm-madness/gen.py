from random import randrange
def gen(N, M):
	C = [randrange(1, 4) for _ in range(N)]
	print(N, M)
	print(' '.join(map(str, C)))

gen(10**5, 2*10**9)
