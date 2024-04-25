#include <iostream>
#include <string>
#include <vector>
#include <utility>
using uci = int;
#define int long long
int solve() {
  int n, k;
  std::cin >> n >> k;
  --k;
  std::vector<int> cows(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> cows[i];
  }

  std::vector<int> big;
  for (int i = 0; i < cows.size() && big.size() < 2; ++i) {
    if (cows[i] > cows[k]) {
      big.push_back(i);
    }
  }
  big.push_back(n);

  return std::max(big[0] - 1, std::min(big[1], k) - big[0] - (big[0] == 0));
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
