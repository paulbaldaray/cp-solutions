#include <cstdio>
#include <algorithm>
/*
3 13
0 1 2

1 10 100
9
denom[i]
(denom[i] / denom[i-1] - 1)
 */
using LL = long long;
LL n, k, T, denom[15], pten[15];
void solve() {
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &denom[i]);
	++k;
	LL ans = 0, first = 1;
	for (LL i = 0; i < n; ++i) {
		LL x = std::min(k, i+1 == n ? k : pten[denom[i+1]] / pten[denom[i]] - 1);
		k -= x;
		ans += x * pten[denom[i]];
	}
	printf("%lld\n", ans);
}
int main() {
	int T;
	scanf("%d", &T);
	pten[0] = 1;
	for (int i = 1; i <= 10; ++i)
		pten[i] = pten[i-1] * 10;
	while (T--)
		solve();
}

/*
3 255
0 1 3
*/

