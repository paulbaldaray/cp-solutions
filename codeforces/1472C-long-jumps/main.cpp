#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
LL solve() {
	LL n;
	cin >> n;
	vector<LL> jumps(n), dp(n+1, 0);
	for (int i = 0; i < n; ++i)
		cin >> jumps[i];
	for (int i = n-1; i >= 0; --i) {
		dp[i] = jumps[i] + dp[min(n, i+jumps[i])];
	}
	return *max_element(dp.begin(), dp.end());
}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
		cout << solve() << '\n';
}
