#include <iostream>
#include <vector>
#include <algorithm>
using LL = long long;
int main() {
	LL n;
	std::cin >> n;
	std::vector<LL> a(n);
	std::vector<std::vector<LL>> dp(n+1, std::vector<LL>(n+1, -1e17));
	for (LL i = 0; i < n; ++i)
		std::cin >> a[i];
	for (LL i = 0; i <= n; ++i)
		dp[i][0] = 0;
	LL ans = 0;
	for (LL p = 1; p <= n; ++p)
		for (LL i = n-1; i >= 0; --i) {
			dp[i][p] = std::max(dp[i+1][p], dp[i+1][p-1] + a[i]);
			if (dp[i][p] >= 0)
				ans = std::max(ans, p);
		}
	std::cout << ans << '\n';
}
