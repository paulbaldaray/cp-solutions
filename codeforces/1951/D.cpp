#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using uci = int;
#define int long long

std::vector<int> solve() {
  int n, k;
  std::cin >> n >> k;

  if (n == k) {
    return {1};
  } else if (2 * k - 1 <= n) {
    return {n - k + 1, 1};
  }

  return {};
}

uci main() {
  int t;
  std::cin >> t;
  while (t--) {
    auto ans = solve();
    if (ans.empty() || ans.size() > 60) {
      std::cout << "NO" << '\n';
      continue;
    }
    std::cout << "YES" << '\n';
    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
      std::cout << (i ? " " : "") << ans[i];
    }
    std::cout << '\n'; }
}
