#include <cstdio>
using LL = long long;
const LL MOD = 998244353, MAX_N = 4e5+20;
LL fact[MAX_N];

inline LL fastPow(LL x, LL e) {
	LL res = 1;
	while (e) {
		if (e % 2)
			res = (res * x) % MOD;
		e /= 2;
		x = (x * x) % MOD;
	}
	return res;
}

inline LL inv(LL x) {
	return fastPow(x, MOD-2);
}

inline LL comb(LL n, LL r) {
	return fact[n] * inv(fact[r] * fact[n-r] % MOD) % MOD;
}

inline LL stars(LL n, LL m) {
	return comb(n+m-1, n);
}

inline LL solve() {
	LL n, f = 0, s = 0, cf = 0, cs = 0;
	scanf("%lld", &n);
	for (LL i = 0, x; i < n; ++i) {
		scanf("%lld", &x);
		if (x == f)
			++cf;
		else if (x > f)
			s = f, cs = cf, f = x, cf = 1;
		else if (x > s)
			s = x, cs = 1;
		else if (x == s)
			++cs;
	}
	if (!cs || cf > 1)
		return fact[n];
	else if (f-s > 1)
		return 0;
	LL not_nice = ((stars(n-cs-1, cs+2) * fact[n-cs-1]) % MOD * fact[cs]) % MOD;
	return (fact[n] - not_nice + MOD) % MOD;
}

int main() {
	LL t;
	scanf("%lld", &t);
	fact[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		fact[i] = (i*fact[i-1]) % MOD;
	while (t--)
		printf("%lld\n", solve());
}
