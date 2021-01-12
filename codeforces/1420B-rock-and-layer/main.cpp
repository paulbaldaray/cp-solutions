#include <iostream>
#include <unordered_map>
#define F first
#define S second
using namespace std;
typedef long long LL;
LL msb(LL x) {
	LL count = 0;
	while (x)
		x /= 2, ++count;
	return count;
}
int main () {
	LL T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		unordered_map<LL, LL> d;
		for (LL i = 0; i < N; ++i) {
			LL x;
			cin >> x;
			++d[msb(x)];
		}
		LL ans = 0;
		for (auto kv : d)
			if (kv.S > 1)
				ans += kv.S*(kv.S-1)/2;
		cout << ans << '\n';
	}
}
