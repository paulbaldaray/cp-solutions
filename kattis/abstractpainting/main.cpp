#include <iostream>
typedef long long LL;
int main() {
	int T;
	std::cin >> T;
	LL r0c0 = 3 * 6; // C(3, 2) * C(4, 2)
	LL r0cx = 2 * 3; // C(2, 1) * C(3, 2)
	LL rxc0 = 2 * 3; // C(2, 1) * C(3, 2)
	LL rxcx = 2 * 1; // C(2, 1) * C(2, 2)
	LL mod = 1e9 + 7;
	for (int t = 0, r, c; t < T; ++t) {
		std::cin >> r >> c;
		LL ans = r0c0;
		for (int i = 0; i < c-1; ++i)
			 ans = (ans * r0cx) % mod;
		for (int i = 0; i < r-1; ++i) {
			ans = (ans * rxc0) % mod;
			for (int j = 0; j < c-1; ++j)
				ans = (ans * rxcx) % mod;
		}
		std::cout << ans % mod << '\n';
	}
}
