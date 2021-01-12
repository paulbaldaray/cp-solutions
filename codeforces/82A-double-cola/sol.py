from math import log2
names = 'Sheldon Leonard Penny Rajesh Howard'.split()
n = int(input())
i = int(log2(n//5+1))
num = 2**i
n -= 5*(2**i-1)+1
print(names[n // num])
