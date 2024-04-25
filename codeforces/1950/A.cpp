#include <iostream>
int main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a < b && b < c) {
      std::cout << "STAIR" << '\n';
    } else if (a < b && b > c) {
      std::cout << "PEAK" << '\n';
    } else {
      std::cout << "NONE" << '\n';
    }
  }
}
