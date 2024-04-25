#include <iostream>
int main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
      for (int j = 0; j < n; ++j) {
        if ((i / 2 + j) % 2 == 0) {
          std::cout << '#' << '#';
        } else {
          std::cout << '.' << '.';
        }
      }
      std::cout << '\n';
    }
  }
}
