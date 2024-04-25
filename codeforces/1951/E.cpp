#include <iostream>
#include <string>
#include <vector>
using uci = int;
#define int long long

std::vector<std::string> solve() {
  std::string s;
  std::cin >> s;

  auto isPal = [](const std::string &s) {
    for (int l = 0, r = s.size() - 1; l < r; ++l, --r) {
      if (s[l] != s[r]) {
        return false;
      }
    }
    return true;
  };

  if (!isPal(s)) {
    return {s};
  }

  if (s.size() < 4) {
    return {};
  }

  int k = s.size();
  for (int i = 1; i < s.size(); ++i) {
    if (s[0] != s[i]) {
      k = i;
      break;
    }
  }

  if (k == s.size()) {
    return {};
  }

  std::vector<std::string>
    c1{s.substr(0, k + 1), s.substr(k + 1, s.size() - k - 1)};

  if (!isPal(c1[0]) && !isPal(c1[1])) {
    return c1;
  }

  std::vector<std::string>
    c2{s.substr(0, k + 2), s.substr(k + 2, s.size() - k - 2)};

  if (!isPal(c2[0]) && !isPal(c2[1])) {
    return c2;
  }

  return {};
}

uci main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
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
