#include <iostream>
#include <vector>
typedef long long LL;
int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<LL> pfx(n+1);
	for (int i = 1; i <= n; ++i)
		std::cin >> pfx[i], pfx[i] += pfx[i-1];
	std::vector<std::vector<LL>> dp(n+1, std::vector<LL>(k+1));
	for (int j = 1; j <= k; ++j)
		for (int i = j*m; i <= n; ++i)
			dp[i][j] = std::max(dp[i-1][j], dp[i-m][j-1] + pfx[i] - pfx[i-m]);
	std::cout << dp[n][k] << '\n';
}
