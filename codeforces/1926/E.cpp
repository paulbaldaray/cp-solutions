#include <iostream>
using uci = int;
#define int long long
uci main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    auto f = [&](int x){ return (n + x) / 2 / x; };
    int p = 1;
    for (; k > f(p); p *= 2) {
      k -= f(p);
    }
    std::cout << (p * (2 * k - 1)) << '\n';
  }
}


