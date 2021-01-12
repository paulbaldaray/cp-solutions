#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	LL T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<LL> a(N), b(N);
		for (LL i = 0; i < N; ++i)
			cin >> a[i];
		for (LL i = 0; i < N; ++i)
			cin >> b[i];
		LL sa = LLONG_MAX;
		for (LL x : a)
			sa = min(sa, x);
		LL sb = LLONG_MAX;
		for (LL x : b)
			sb = min(sb, x);
		LL ans = 0;
		for (LL i = 0; i < N; ++i) {
			LL da = a[i] - sa, db = b[i] - sb;
			LL little = min(da, db);
			da -= little, db -= little;
			ans += little + da + db;
		}
		cout << ans << '\n';
	}
}
