#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long LL;
int main() {
	LL T, N, Q;
	cin >> T;
	while (T--) {
		cin >> N >> Q;
		vector<LL> a(N);
		for (LL i = 0; i < N; ++i)
			cin >> a[i];
		LL ans = 0, last = 0, turn = 0;
		for (LL i = 0; i < N; ++i) {
			if (!turn && (i+1 == N || a[i] > a[i+1])) {
				ans += a[i];
				last = a[i], turn ^= 1;
			} else if (turn && (i+1 == N || a[i] < a[i+1])) {
				ans -= a[i];
				last = a[i], turn ^= 1;
			}
		}
		if (turn == 0)
			ans += last;
		cout << ans << '\n';
	}
}
