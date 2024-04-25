#include <iostream>
using uci = int;
#define int long long
// MAX_N = 500

void solve() {
  int n;
  std::cin >> n;

  int s = 0, m = 2*n;
  for (int i = 1; i <= n; ++i) {
    s += (2 * i - 1) * i;
  }

  std::cout << s << " " << m << '\n';
  for (int i = 1; i <= n; ++i) {
    std::cout << 1 << " " << (n - i + 1);
    for (int j = 1; j <= n; ++j) {
      std::cout << " " << j;
    }
    std::cout << '\n';

    std::cout << 2 << " " << (n - i + 1);
    for (int j = 1; j <= n; ++j) {
      std::cout << " " << j;
    }
    std::cout << '\n';
  }
}

uci main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}
