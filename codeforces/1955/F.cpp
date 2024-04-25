#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << (a/2 + b/2 + c/2 + (a&b&c&1) + d/2) << '\n';
  }
}
