s = list(map(int, input()))
ans = 0
mod = 10**9 + 7
n = len(s)
s.reverse()
x = 0
power = 1
for r, d in enumerate(s):
	l = n - r - 1
	ans += ((l*(l+1)//2)%mod*(d*power%mod))%mod
	ans %= mod
	ans += (d*x)%mod
	ans %= mod
	x += (power*((r+1)%mod))%mod
	x %= mod
	power *= 10
	power %= 10
print(ans%mod)
