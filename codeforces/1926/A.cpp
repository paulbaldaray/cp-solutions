#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    int a = 0;
    for (int i = 0; i < s.size(); ++i) {
      a += s[i] == 'A';
    }
    std::cout << (a >= 3 ? 'A' : 'B') << '\n';
  }
}
