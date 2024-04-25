#include <cstdint>
#include <iostream>
#include <cmath>
#define int long long

int log2Ceil(int x) {
  int i = 0;
  while ((1 << i) < x) {
    ++i;
  }
  return i;
}

int solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if (c == 0) {
    return a || b ? -1 : 0;
  }

  if (a != c - 1) {
    return -1;
  }

  int min_height = log2Ceil(c);
  int leaf = (1 << min_height);
  if (c != leaf) {
    int lower_leaf = 2 * (c - (leaf / 2));
    int higher_leaf = c - lower_leaf;
    b = std::max(0LL, b - higher_leaf);
  }
  return min_height + (b / c) + (b % c > 0);
}

int32_t main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}

