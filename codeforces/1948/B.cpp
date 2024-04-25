#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#define int long long

int splitGreater(int current, int last_val) {
  if (current < last_val) {
    return -2;
  }
  std::string s = std::to_string(current);
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] - '0' < last_val) {
      return current;
    }
    last_val = s[i] - '0';
  }
  return last_val;
}

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  int last_val = -1;
  for (int i = 0; i < n; ++i) {
    last_val = splitGreater(a[i], last_val);
    if (last_val == -2) {
      return false;
    }
  }

  return true;
}

int32_t main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
}
