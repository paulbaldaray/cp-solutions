#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
using uci = int;
#define int long long
inline int solve() {
  std::string s;
  std::vector<std::array<int, 2>> points[2];
  for (int r = 0; r < 7; ++r) {
    std::cin >> s;
    for (int c = 0; c < 7; ++c) {
      if (s[c] == 'B') {
        points[(r + c) % 2].push_back({r, c});
      }
    }
  }

  auto calc = [&](int w, int k) -> bool {
    int n = points[w].size();
    std::vector<bool> perm(n, true);
    std::fill(perm.begin(), perm.begin() + k, false);
restart:
    char count[9][9]{};
    for (int i = 0; i < n; ++i) {
      if (perm[i]) {
        auto [r, c] = points[w][i];
        ++count[r+1][c+1];
        for (int y = -1; y < 2; y += 2) {
          for (int x = -1; x < 2; x += 2) {
            if (++count[r+y+1][c+x+1] == 5) {
              if (std::next_permutation(perm.begin(), perm.end())) {
                goto restart;
              }
              return false;
            }
          }
        }
      }
    }
    return true;
  };

  int ans = 8;
  for (int w = 0; w < 2; ++w) {
    for (int k = 0; k < 4; ++k) {
      if (calc(w, k)) {
        ans += k - 4;
        break;
      }
    }
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
