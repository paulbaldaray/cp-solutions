#include <iostream>
#include <string>
using i32safe = int;
#define int long long
inline int solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  for (int sz = 1; sz <= n / 2; ++sz) {
    if (n % sz != 0) {
      continue;
    }

    int total = 0, total2 = 0;
    for (int i = sz; i < n; i += sz) {
      int diff = 0, diff2 = 0;
      for (int j = 0; j < sz; ++j) {
        diff += s[j] != s[i + j];
        diff2 += s[n-1-j] != s[i-1-j];
      }

      if (diff > 0) {
        total += diff == 1 ? 1 : n;
      }
      if (diff2 > 0) {
        total2 += diff2 == 1 ? 1 : n;
      }
    }

    if (total <= 1 || total2 <= 1) {
      return sz;
    }
  }

  return n;
}
i32safe main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}
