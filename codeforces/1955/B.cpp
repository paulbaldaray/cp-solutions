#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using uci = int;
#define int long long
bool solve() {
  int n, c, d;
  std::cin >> n >> c >> d;
  std::multiset<int> a;
  for (int i = 0, x; i < n*n; ++i) {
    std::cin >> x;
    a.insert(x);
  }

  std::vector<std::vector<int>> s(n, std::vector<int>(n));
  s[0][0] = *a.begin();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i) {
        s[i][j] = s[i - 1][j] + c;
      }
      if (j) {
        s[i][j] = s[i][j - 1] + d;
      }
      if (a.count(s[i][j])) {
        a.erase(a.find(s[i][j]));
      } else {
        return false;
      }
    }
  }

  return a.empty();
}

uci main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
}
