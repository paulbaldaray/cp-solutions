#include <iostream>
#include <string>
#include <vector>

int solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  std::vector<bool> uninv;
  for (int k = n; k > 1; --k) {
    uninv.assign(n + 1, false);
    bool inv = false;
    for (int i = 0; i < n - k + 1; ++i) {
      inv ^= uninv[i];
      bool is_zero = (s[i] == '0') ^ inv;
      if (is_zero) {
        inv ^= true;
        uninv[i + k] = true;
      }
    }

    for (int i = n - k + 1; i < n; ++i) {
      inv ^= uninv[i];
      bool is_zero = (s[i] == '0') ^ inv;
      if (is_zero) {
        goto try_next_k;
      }
    }
    return k;
try_next_k:;
  }
  return 1;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}
