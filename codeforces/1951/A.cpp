#include <iostream>
#include <string>
#include <vector>
using uci = int;
#define int long long
bool solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  std::vector<int> v;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      v.push_back(i);
    }
  }

  int m = v.size();
  if (m % 2 == 1) {
    return false;
  }

  for (int i = 0; i < m / 2; ++i) {
    if (v[i] + 1 == v[m/2+i]) {
      return false;
    }
  }

  return true;
}

uci main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
}
