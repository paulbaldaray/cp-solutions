#include <iostream>
const int MAX_P = 2e2 + 10;
static int dp[MAX_P + 5][MAX_P + 5][MAX_P + 5];

inline void precalc() {
  for (int i = 0; i <= MAX_P; ++i) {
    for (int j = 0; j <= MAX_P; ++j) {
      for (int k = 0; k <= MAX_P; ++k) {
        if ((i | j | k) == 0) {
          dp[i][j][k] = 0;
          continue;
        }
        int best = 0;
        if (i) {
          best = std::max(best, dp[i-1][j][k]);
        }
        if (j) {
          best = std::max(best, dp[i][j-1][k]);
        }
        if (k) {
          best = std::max(best, dp[i][j][k-1]);
        }
        dp[i][j][k] = best + (i % 2 == j % 2 && j % 2 == k % 2);
      }
    }
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  precalc();
  while (t--) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << (dp[a][b][c] + d / 2) << '\n';
  }
}
