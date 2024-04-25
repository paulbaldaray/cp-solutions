#include <iostream>
#include <vector>
using uci = int;
#define int long long
inline int solve() {
  int n;
  std::cin >> n;
  std::vector<int> f(n, 0);

  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    ++f[x];
  }

  bool lifeline = true;
  for (int x = 0; x < n; ++x) {
    if (f[x] == 0 or f[x] == 1 and !lifeline) {
      return x;
    }
    lifeline &= f[x] > 1;
  }

  return n;
}

uci main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}
