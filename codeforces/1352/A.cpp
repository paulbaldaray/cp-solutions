#include <iostream>
#include <vector>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> ans;
    for (int i = 1; n; i *= 10) {
      if (n % 10) {
        ans.push_back(i * (n % 10));
      }
      n /= 10;
    }

    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
      std::cout << (i ? " " : "")<< ans[i];
    }
    std::cout << '\n';
  }
}
