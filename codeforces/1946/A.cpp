#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using uci = int;
#define int long long

template <typename T>
std::ostream &operator<<(std::ostream &out, std::vector<T> v) {
  out << "{";
  for (int i = 0; i < v.size(); ++i) {
    std::cout << (i ? "," : "") << v[i];
  }
  return out << "}";
}
int solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  int p = std::ceil(n / 2.0), p_end = n;

  for (int i = n; i >= 1; --i) {
    if (a[i] == a[p]) {
      p_end = i;
      break;
    }
  }

  return p_end - p + 1;
}
uci main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}
