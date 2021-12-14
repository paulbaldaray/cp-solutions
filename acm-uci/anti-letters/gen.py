from random import randrange, sample
from string import ascii_lowercase as alpha
N = 10**5
K = 2
lets = sample(alpha, K)
thresh = sum(randrange(10) for _ in range(10)) // 10
def rchar():
	let = lets[randrange(len(lets))]
	if randrange(10) > thresh:
		return let.upper()
	return let
S = ''.join(rchar() for _ in range(N))
P = ''.join(rchar() for _ in range(N//1000))
print(S)
print(P)
