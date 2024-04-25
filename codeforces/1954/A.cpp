#include <iostream>
using uci = int;
#define int long long
bool solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  if (n == k || m == 1) {
    return false;
  }
  int high = (n + m - 1) / m;
  if (n - high <= k) {
    return false;
  }
  return true;
}

uci main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
}
