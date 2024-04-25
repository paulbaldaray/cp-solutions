#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using uci = int;
#define int long long
int solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::array<int, 2>> v(n);
  for (int i = 0, x; i < n; ++i) {
    std::cin >> v[i][0];
    v[i][1] = -i;
  }

  std::sort(v.begin(), v.end());
  std::vector<std::array<int, 2>> alloc(n);

  int rem = k;
  for (int i = 0; i < n; ++i) {
    int x = std::min(rem, m);
    alloc[-v[i][1]] = {x, v[i][0]};
    rem -= x;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto [x, a] = alloc[i];
    ans += x * a + (k - x) * x;
    k -= x;
  }

  return ans;
}

uci main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}
