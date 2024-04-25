#include <iostream>
#include <vector>
using uci = int;
#define int long long
const int MOD = 1e9 + 7;

int safe_mod(int x) {
  while (x < 0) {
    x += MOD;
  }
  return x;
}

int solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  int msum = 0, sum = 0, rest = 0;
  for (int x : a) {
    rest += x;
    sum = std::max(0LL, sum) + x;
    msum = std::max(msum, sum);
  }

  msum = std::max(0LL, msum) % MOD;

  rest = safe_mod(rest - msum);

  for (int i = 0; i < k; ++i) {
    msum = (msum * 2) % MOD;
  }

  return (msum + rest) % MOD;
}

uci main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}
