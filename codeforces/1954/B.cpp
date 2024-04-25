#include <iostream>
#include <vector>
using uci = int;
#define int long long
int solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  if (a[0] != a.back()) {
    return 0;
  }

  int last = -1, mingap = n;
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[0]) {
      mingap = std::min(mingap, i - last - 1);
      last = i;
    }
  }
  mingap = std::min(mingap, n - last - 1);

  return mingap == n ? -1 : mingap;
}

uci main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}
