#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>

using i32safe = int;
#define int long long

class EertreE {
  int log_sfx;
  std::vector<int> len, sfx, longest;
  std::vector<std::map<char, int>> nxt;
  std::vector<std::vector<int>> dp;

  void pushNewNode(int l, int s) {
    len.push_back(l);
    sfx.push_back(s);
    nxt.push_back({});
  };

public:
  EertreE(const std::string &s) {
    pushNewNode(-1, 0);
    pushNewNode(0, 0);
    int u = 1;
    for (int i = 0; i < s.size(); ++i) {
      while (i <= len[u] or s[i-len[u]-1] != s[i]) {
        u = sfx[u];
      }

      if (!nxt[u][s[i]]) {
        nxt[u][s[i]] = len.size();
        pushNewNode(len[u] + 2, 1);


        if (len.back() > 1) {
          int v = sfx[u];
          while (i <= len[v] or s[i-len[v]-1] != s[i]) {
            v = sfx[v];
          }
          sfx.back() = nxt[v][s[i]];
        }
      }

      u = nxt[u][s[i]];
      longest.push_back(u);
    }

    int m = sfx.size();
    log_sfx = std::log2(m + 1);
    dp.assign(m, std::vector<int>(log_sfx + 1, 0));
    for (int u = 0; u < m; ++u) {
      dp[u][0] = sfx[u];
    }

    for (int k = 1; k <= log_sfx; ++k) {
      for (int u = 0; u < m; ++u) {
        dp[u][k] = dp[dp[u][k-1]][k-1];
      }
    }
  }

  bool isPalindrome(int l, int r) {
    int u = longest[r], target = r - l + 1;
    for (int k = log_sfx; k >= 0; --k) {
      if (len[dp[u][k]] >= target) {
        u = dp[u][k];
      }
    }
    return len[u] == target;
  }
};

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string s;
  std::cin >> s;
  EertreE eertree(s);

  std::vector<int> diff1, diff2;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i-1]) {
      diff1.push_back(i);
    }
    if (i > 1 && s[i] != s[i-2]) {
      diff2.push_back(i);
    }
  }

  for (int l, r; q--; ){
    std::cin >> l >> r;
    --l, --r;

    int ans = 0, len = r - l + 1;
    auto not_same = std::lower_bound(diff1.begin(), diff1.end(), l + 1);
    if (not_same != diff1.end() && *not_same <= r) {
      auto asum = [](int n, int a1, int d) {
        return n * (2*a1 + (n - 1) * d) / 2;
      };

      auto not_alt = std::lower_bound(diff2.begin(), diff2.end(), l + 2);
      if (not_alt != diff2.end() && *not_alt <= r) {
        ans = asum(len - 2, 2, 1); // (n != 1, n != len)
      } else {
        ans = asum((len - 1) / 2, 2, 2); // (n != 1, n != len) round up odd
      }
    }


    if (!eertree.isPalindrome(l, r)) {
      ans += len;
    }

    std::cout << ans << "\n";
  }
}

i32safe main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}
