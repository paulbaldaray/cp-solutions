#include <iostream>
using uci = int;
#define int long long
uci main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    int n, a, b;
    std::cin >> n >> a >> b;
    b = std::min(b, 2*a);
    int x = n % 2;
    int y = n / 2;
    std::cout << (x * a + y * b) << '\n';
  }
}
