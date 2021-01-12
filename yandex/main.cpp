#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c, d, e, ans;
	cin >> a >> b >> c >> d >> e;
	ans = a;
	ans += b;
	e = max(e-b, 0);
	ans += c;
	int dc_pair = min(c, d);
	c -= dc_pair;
	d -= dc_pair;
	e = max(e-c*2, 0);
	int extra_d = d % 2;
	d /= 2;
	ans += d;
	e = max(e-d, 0);
	if (extra_d) {
		++ans;
		e -= 3;
	}
	e = max(e, 0);
	int extra_e = e % 5;
	ans += e / 5;
	if (extra_e)
		++ans;
	cout << ans << endl;
}
