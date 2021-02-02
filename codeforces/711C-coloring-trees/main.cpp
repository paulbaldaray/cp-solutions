#include <iostream>
#include <algorithm>
typedef long long LL;
const LL MAX_N = 100+10, INF = 1e16;
int trees[MAX_N], cost[MAX_N][MAX_N];
LL dp[MAX_N][MAX_N][MAX_N];
int main() {
	int N, M, K;
	std::cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i)
		std::cin >> trees[i];
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			std::cin >> cost[i][j];
	std::fill(&dp[0][0][0], &dp[0][0][0]+(MAX_N)*(MAX_N)*(MAX_N), INF);
	for (int k = K; k >= 0; --k)
		for (int i = N+1; i >= 1; --i)
			for (int j = 0; j <= M; ++j) {
				if (i == N+1)
					dp[i][j][k] = k == K ? 0 : INF;
				else if (trees[i] != 0)
					dp[i][j][k] = dp[i+1][trees[i]][k+(trees[i]!=j)];
				else
					for (int c = 1; c <= M; ++c)
						dp[i][j][k] = std::min(dp[i][j][k], dp[i+1][c][k+(c!=j)] + cost[i][c]);
			}
	std::cout << (dp[1][0][0] == 1e16 ? -1 : dp[1][0][0]) << '\n';
}
