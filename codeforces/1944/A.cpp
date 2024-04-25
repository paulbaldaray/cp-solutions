#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    std::cout << (k >= n - 1 ? 1 : n) << '\n';
  }
}
