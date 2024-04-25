#include <iostream>
#include <vector>
#include <map>
using uci = int;
#define int long long

int solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::map<int, int> bc, ac;
  for (int i = 0, x; i < m; ++i) {
    std::cin >> x;
    ++bc[x];
  }

  int matches = 0;
  for (int i = 0; i < m; ++i) {
    ++ac[a[i]];
    if (bc[a[i]] > 0 && ac[a[i]] <= bc[a[i]]) {
      ++matches;
    }
  }

  int ans = matches >= k;

  for (int l = 0, r = m; r < n; ++l, ++r) {
    --ac[a[l]];
    if (bc[a[l]] > 0 && ac[a[l]] < bc[a[l]]) {
      --matches;
    }

    ++ac[a[r]];
    if (bc[a[r]] > 0 && ac[a[r]] <= bc[a[r]]) {
      ++matches;
    }

    ans += matches >= k;
  }

  return ans;
}

uci main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}
