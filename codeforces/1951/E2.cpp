#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using uci = int;
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
  }

  void binaryLift() {
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

std::vector<std::string> solve() {
  std::string s;
  std::cin >> s;
  EertreE eertree(s);
  eertree.binaryLift();
  if (!eertree.isPalindrome(0, s.size() - 1)) {
    return {s};
  }

  for (int i = 1; i < s.size() / 2 + 2 && i < (int)s.size() - 2; ++i) {
    bool first = eertree.isPalindrome(0, i);
    bool second = eertree.isPalindrome(i + 1, (int) s.size() - 1);
    if (!first && !second) {
      return {s.substr(0, i + 1), s.substr(i + 1, s.size() - i - 1)};
    }
  }

  return {};
}

uci main() {
  int t;
  std::cin >> t;
  while (t--) {
    auto ans = solve();
    if (ans.empty()) {
      std::cout << "NO" << '\n';
      continue;
    }
    std::cout << "YES" << '\n';
    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
      std::cout << (i ? " " : "") << ans[i];
    }
    std::cout << '\n';
  }
}
