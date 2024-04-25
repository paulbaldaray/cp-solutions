#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
using uci = int;
#define int long long

const int mod = 998244353;
const int MAX_V = 5e3 + 5;
int a[MAX_V + 5]{};
int dp[MAX_V + 5][MAX_V + 5]{};

int solve() {
  int n;
  std::cin >> n;

  int high = 0, total = 0;
  bool has_odd = false;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    total += a[i];
    high = std::max(high, a[i]);
    has_odd |= (a[i] % 2);
  }

  if (n == 1) {
    return a[1];
  }

  dp[0][0] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= high; ++j) {
      dp[i][j] = (dp[i - 1][j] + (a[i] <= j ? dp[i - 1][j - a[i]] : 0)) % mod;
    }
  }

  int pow = 1;
  for (int x = n - 2, a = 2; x > 0; x /= 2) {
    if (x & 1) {
      pow = (pow * a) % mod;
    }
    a = (a * a) % mod;
  }

  int ans = (total * pow) % mod;
  if (has_odd) {
    ans = (ans + pow) % mod;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < a[i] - 1; ++j) {
      ans = (ans - (j + a[i] + 1) / 2 * dp[n][j]) % mod;
      ans = (ans + a[i] * dp[n][j]) % mod;
    }
  }

  return ans % mod;
}

uci main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  std::cout << solve() << '\n';
}
