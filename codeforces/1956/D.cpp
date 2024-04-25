#include <iostream>
using uci = int;
#define int long long

const int MAX_N = 20;
int a[MAX_N + 5];
uci main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
}
