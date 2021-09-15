#include <cstdio>
#include <algorithm>
int c[510], n, dp[510][510]{};
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &c[i]), dp[i][i] = 1;
	for (int sz = 0; sz < n; ++sz)
		for (int i = 0, j = i+sz+1; j < n; ++i, ++j) {
			dp[i][j] = dp[i+1][j] + 1;
			if (i+1 <= j && c[i] == c[i+1])
				dp[i][j] = dp[i+2][j] + 1;
			for (int k = i+2; k <= j; ++k)
				if (c[i] == c[k])
					dp[i][j] = std::min(dp[i][j], dp[i+1][k-1] + dp[k+1][j]);
		}
	printf("%d\n", dp[0][n-1]);
}
