from math import log2
MOD = 10**9+7
def geteo(x):
	n = e = o = 0
	while (2**(n+1))-1 <= x:
		if n % 2:
			e += 1 << n
		else:
			o += 1 << n
		n+=1
	x -= e + o
	if n % 2:
		e += x
	else:
		o += x
	return e, o

def arsum(a, n, d=2):
	return (n*(2*a + d*(n-1)) // 2) % MOD

def calc(x):
	e, o = geteo(x)
	return (arsum(2, e) + arsum(1, o)) % MOD

l, r = 88005553535, 99999999999
# l, r = map(int, input().split())
print((calc(r) - calc(l-1)+MOD)%MOD)
