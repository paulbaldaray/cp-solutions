#include <iostream>
using namespace std;
bool solve() {
	int w, h, n;
	cin >> w >> h >> n;
	int count = 0;
	while (!(w&1))
		w>>=1, ++count;
	while (!(h&1))
		h>>=1, ++count;
	long long ans = 1;
	for (int i = 0; i < count && ans < n; ++i)
		ans <<= 1;
	return ans >= n;
}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
		cout << (solve() ? "YES" : "NO") << '\n';
}
