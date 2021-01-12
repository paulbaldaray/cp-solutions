#include <iostream>
using namespace std;
int main() {
	long long TC; cin >> TC;
	while (TC--) {
		long long l, m, r, a, b, c;
		cin >> l >> r >> m;
		for (a = l; a <= r; ++a) {
			long long rem = m % a, rem2 = a - m % a;
			if (rem <= r - l && a <= m) {
				b = r, c = r - rem; break;
			} else if (rem2 <= r - l && (m + rem2) % a == 0) {
				b = l, c = l + rem2; break;
			}
		}
		cout << a << " " << b << " " << c << '\n';
	}
}
