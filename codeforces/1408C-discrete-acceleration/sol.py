from math import inf
T = int(input())
for _ in range(T):
	N, L = map(int, input().split())
	a = list(map(int, input().split()))
	l, r = 0, N-1
	s1, s2 = 1, 1
	d1, d2 = 0, L
	time = 0
	error = 10**-8
	while True:
		rb =  (d2-d1)/(s1+s2)
		r1 = (a[l]-d1)/s1 if l <= r else inf
		r2 = (d2-a[r])/s2 if l <= r else inf
		small = min((rb, r1, r2))
		time += small
		d1 += small*s1
		d2 -= small*s2
		if rb-small < error:
			break
		if r1-small < error:
			s1 += 1
			l += 1
		if r2-small < error:
			s2 += 1
			r -= 1
	print(time)
'''
s1 * t + s2 * t = (d2-d1)
(s1+s2) * t = (d2-d1)
t = (d2-d1)/(s1+s2)
'''
