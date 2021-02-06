#include <iostream>
#include <algorithm>
typedef long long LL;
const LL MAX_N = 1e5+10, INF = 3e18;
LL N, arr[MAX_N], dp[MAX_N][4], PQR[4];
int main() {
	std::cin >> N >> PQR[1] >> PQR[2] >> PQR[3];
	for (int i = 1; i <= N; ++i)
		std::cin >> arr[i];
	std::fill(&dp[0][0], &dp[0][0]+MAX_N*4, -INF);
	for (int k = 0; k <= 3; ++k)
		for (int i = 1; i <= N; ++i) {
			if (k == 0)
				dp[i][k] = 0;
			else
				dp[i][k] = std::max(dp[i-1][k], dp[i][k-1]+PQR[k]*arr[i]);
		}
	std::cout << dp[N][3] << '\n';
}
