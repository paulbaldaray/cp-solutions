#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
inline LL bananas(LL x, LL y) {
	++x, ++y;
	LL row = x*((y-1) + (x-1));
	return row*(y / 2) + (y%2) * (row/2);
}
int main() {
	LL m, b;
	cin >> m >> b;
	LL ans = 0;
	for (LL i = b; i >= 0; --i) {
		LL y = -1.0/m * i + b, x = -(i-b)*m;
		ans = max(ans, max(bananas(i, y), bananas(x, i)));
	}
	cout << ans << '\n';
}
