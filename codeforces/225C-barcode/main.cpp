#include <iostream>
const int MAX_M = 1e3+5;
int dp[MAX_M][MAX_M][2], wpixels[MAX_M] = {0};
int main() {
	int n, m, x, y;
	std::cin >> n >> m >> x >> y;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			char v;
			std::cin >> v;
			wpixels[j] += (v == '.');
		}
	for (int i = m; i >= 0; --i)
		for (int j = i; j >= 0; --j)
			for (int w = 0; w < 2; ++w) {
				if (i == m || j > y) {
					dp[i][j][w] = x <= j && j <= y ? 0 : n*m;
					continue;
				}
				dp[i][j][w] = dp[i+1][j+1][w] + (w ? n - wpixels[i] : wpixels[i]);
				if (j < x)
					continue;
				dp[i][j][w] = std::min(dp[i][j][w], dp[i+1][1][!w] + (w ? wpixels[i] : n - wpixels[i]));
			}
	std::cout << std::min(dp[0][0][0], dp[0][0][1]) << '\n';
}
