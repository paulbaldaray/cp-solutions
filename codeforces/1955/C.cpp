#include <iostream>
#include <deque>
using uci = int;
#define int long long

int solve() {
  int n, k;
  std::cin >> n >> k;
  std::deque<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  int z = k;
  while (z > 0 && !a.empty()) {
    if (a.size() == 1) {
      if (a.front() <= z) {
        a.pop_front();
      }
      break;
    }

    bool front = (k - z) % 2 == 0;
    int f = 2 * a.front() - front;
    int b = 2 * a.back() - (!front);
    int m = std::min(f, b);
    if (z < m) {
      break;
    }
    z -= m;
    if (f < b) {
      a.back() -= a.front() - (front);
      a.pop_front();
    } else {
      a.front() -= a.back() - (!front);
      a.pop_back();
    }
  }

  return n - a.size();
}

uci main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}
