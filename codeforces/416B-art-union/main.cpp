#include <iostream>
#include <vector>
int main() {
	int M, N;
	std::cin >> M >> N;
	std::vector<std::vector<int>> paintings(M+1, std::vector<int>(N+1));
	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
			std::cin >> paintings[i][j];
	std::vector<std::vector<int>> dp(M+1, std::vector<int>(N+1));
	for (int j = 1; j <= N; ++j)
		for (int i = 1; i <= M; ++i)
			dp[i][j] = paintings[i][j] + std::max(dp[i-1][j], dp[i][j-1]);
	for (int i = 1; i <= M; ++i)
		std::cout << dp[i][N] << (i == M ? "" : " ");
	std::cout << '\n';
}
