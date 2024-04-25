#include <iostream>
#include <map>
#include <cmath>
int main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::map<int, int> count;
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      ++count[x];
    }
    int ans = 0, mask = (1LL << 31) - 1;
    while (!count.empty()) {
      auto [x, f1] = *count.begin();
      int y = ~x & mask;
      int f2 = count[y];
      ans += std::max(f1, f2);
      count.erase(x);
      count.erase(y);
    }
    std::cout << ans << '\n';
  }
}
