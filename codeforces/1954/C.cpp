#include <iostream>
#include <string>
#include <array>
using uci = int;
#define int long long
std::string x, y;

void solve() {
  std::cin >> x >> y;
  bool swapped = false;
  // x <= y
  int x_start = -1;
  if (y.size() < x.size()) {
    std::swap(x, y);
    swapped = true;
  } else if (y.size() == x.size()) {
    for (int i = 0; i < x.size(); ++i) {
      if (x[i] == y[i]) {
        continue;
      }
      if (x[i] > y[i]) {
        std::swap(x, y);
        swapped = true;
      }
      x_start = i;
      break;
    }
  }

  for (int i = x.size() - 1, j = y.size() - 1; i > x_start; --i, --j) {
    if (x[i] < y[j]) {
      std::swap(x[i], y[j]);
    }
  }

  if (swapped) {
    std::swap(x, y);
  }
}

uci main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
    std::cout << x << '\n';
    std::cout << y << '\n';
  }
}
