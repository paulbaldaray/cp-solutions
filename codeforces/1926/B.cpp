#include <iostream>
#include <string>
#include <vector>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> v[i];
    }
    int count = 0, lo = n, hi = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (v[i][j] == '1') {
          ++count;
          lo = std::min(lo, j);
          hi = std::max(hi, j);
        }
      }
    }
    int sqr_count = (hi - lo + 1) * (hi - lo + 1);
    std::cout << (sqr_count == count ? "SQUARE" : "TRIANGLE") << '\n';
  }
}
