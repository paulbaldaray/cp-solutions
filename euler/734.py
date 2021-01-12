from primesieve import *
from math import factorial
def tuples(n,k):
    ps = primes(n).tolist()
    ret = []
    for i in range(len(ps)**k):
        curry = []
        for j in range(k):
            curry.append(ps[i%len(ps)])
            i //= len(ps)
        if sorted(curry) == curry: ret.append(curry)
    return ret
        
def check(t):
    res = t[0]
    for i in range(1,len(t)):
        res |= t[i]
    #print(res, t, res in pset)
    mult = factorial(len(t))
    for a in set(t):
        mult //= factorial(sum(x == a for x in t))
    return (res in pset) * mult


def solve(n,k):
    return sum(check(t) for t in tuples(n,k))

for n in (11,):
    pset = set(primes(n).tolist())
    print(len(pset))
    for k in range(1, 20):
        ans = solve(n,k)
        print(n,k, ans)
 
'''

#primes -> recurrence
2 -> 2(n-1)
3 -> 2(n-1) - 1
4 -> 4(n-1)


'''