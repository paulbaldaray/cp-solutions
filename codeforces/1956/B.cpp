#include <iostream>
const int MAX_N = 2e5 + 5;
bool vis[MAX_N];
int a[MAX_N];
int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
      vis[i] = false;
      std::cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (vis[a[i]]) {
        ++ans;
      } else {
        vis[a[i]] = true;
      }
    }
    std::cout << ans << '\n';
  }
}
