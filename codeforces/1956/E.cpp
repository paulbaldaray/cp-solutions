#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <set>
using uci = int;
#define int long long
const int MAX_N = 2e5 + 5;
int a[MAX_N + 5]{};

inline int inc(int i, int n) { return (i + 1) % n; }
inline int dec(int i, int n) { return (i - 1 + n) % n; }

void solve() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::deque<std::array<int, 2>> win;
  std::vector<bool> vis(n);
  std::vector<int> ans;
  for (int i = 0; i < n; ++i) {
    a[inc(i, n)] = std::max(0LL, a[inc(i, n)] - a[i]);
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] == 0 && a[inc(i, n)] > 0) {
      win.push_back({inc(i, n), (int)1e9 + 30});
    }
  }

  while (!win.empty()) {
    auto [i, x] = win.front();
    win.pop_front();

    if (vis[i]) {
      continue;
    }
    vis[i] = true;

    if (a[i] <= 0) {
      win.push_back({inc(i, n), (int)1e9 + 30});
      continue;
    }

    ans.push_back(i + 1);
    int j = inc(i, n);

    int jx = std::min(x, (a[j] - 1 + a[i]) / a[i]) - (i < j);
    a[j] = 0;

    win.push_back({j, jx});
  }

  std::cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); ++i) {
    std::cout << (i ? " " : "") << ans[i];
  }
  std::cout << '\n';
}

uci main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}
