#include <iostream>
#include <vector>
#include <numeric>
using uci = int;
#define int long long
std::vector<int> solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> ans;
  bool nodd = n % 2, kodd = k % 2;
  if (nodd && kodd) {
    for (int i = 0; i < k - 1; ++i) {
      ans.push_back(1);
    }
    int val = n - (k - 1);
    if (val > 0) {
      ans.push_back(val);
    }
  } else if (!nodd && kodd){
    for (int i = 0; i < k - 1; ++i) {
      ans.push_back(2);
    }
    int val = n - 2*(k - 1);
    if (val > 0) {
      ans.push_back(val);
    }
  } else if (!nodd && !kodd) {
    for (int i = 0; i < k - 2; ++i) {
      ans.push_back(1);
    }
    int val = (n - (k - 2))/2;
    if (val > 0) {
      ans.push_back(val);
      ans.push_back(val);
    }
  } else {
    return {};
  }

  if (ans.size() != k || std::accumulate(ans.begin(), ans.end(), 0) != n) {
    return {};
  }

  return ans;
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
    for (int i = 0; i < ans.size(); ++i) {
      std::cout << (i ? " " : "") << ans[i];
    }
    std::cout << '\n';
  }
}
