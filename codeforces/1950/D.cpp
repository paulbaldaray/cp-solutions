#include <iostream>
#include <vector>
using i32safe = int;
#define int long long
const int MAX_N = 1e5 + 10;
i32safe main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  std::vector<int> nums = {0};
  for (int i = 1; i < MAX_N; i *= 10) {
    int total = nums.size();
    for (int j = 0; j < total; ++j) {
      int x = nums[j] + i;
      if (x <= MAX_N) {
        nums.push_back(x);
      }
    }
  }

  while (t--) {
    int n;
    std::cin >> n;
    for (int i = nums.size() - 1; i > 1; --i) {
      while (nums[i] <= n && n % nums[i] == 0) {
        n /= nums[i];
      }
    }
    std::cout << (n == 1 || n == 0 ? "YES" : "NO") << '\n';
  }
}
