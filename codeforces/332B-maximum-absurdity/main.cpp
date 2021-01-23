#include <iostream>
#include <vector>
#include <algorithm>
typedef long long LL;
typedef std::vector<LL> VL;
int main() {
	int n, k;
	std::cin >> n >> k;
	VL pfx(n+1);
	for (int i = 1; i <= n; ++i)
		std::cin >> pfx[i], pfx[i] += pfx[i-1];
	std::vector<VL> dp(2, VL(n+1, 0)), bptr(2, VL(n+1, 1));
	for (int i = 1; i+k-1 <= n; ++i) {
		LL prev = dp[0][i-1], sum = pfx[i+k-1]-pfx[i-1];
		if (i != 1 && prev >= sum)
			dp[0][i] = prev, bptr[0][i] = bptr[0][i-1];
		else
			dp[0][i] = sum, bptr[0][i] = i;
	}
	for (int i = k+1; i <= n; ++i) {
		LL prev = dp[1][i-1], sum = i+k-1 <= n ? dp[0][i-k]+pfx[i+k-1]-pfx[i-1] : -1;
		if (i != k+1 && prev >= sum)
			dp[1][i] = prev, bptr[1][i] = bptr[1][i-1];
		else
			dp[1][i] = sum, bptr[1][i] = i;
	}
	std::cout << bptr[0][bptr[1][n]-k] << ' ' << bptr[1][n] << '\n';
}
