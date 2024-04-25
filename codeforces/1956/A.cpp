#include <iostream>
#include <vector>
#include <algorithm>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int k, q;
    std::cin >> k >> q;
    std::vector<int> a(k), n(q);
    for (int i = 0; i < k; ++i) {
      std::cin >> a[i];
    }
    int small = *std::min_element(a.begin(), a.end());
    for (int i = 0; i < q; ++i) {
      std::cin >> n[i];
    }

    for (int i = 0; i < q; ++i) {
      std::cout << (i ? " " : "") << std::min(small - 1, n[i]);
    }
    std::cout << '\n';
  }
}
