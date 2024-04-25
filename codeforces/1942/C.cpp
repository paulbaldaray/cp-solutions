#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using i32safe = int;
#define int long long
int solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> v(x);

  if (x + y == 0) {
    return 0;
  }

  for (int i = 0; i < x; ++i) {
    std::cin >> v[i];
    --v[i];
  }

  if (x == 0) {
    ++x, --y;
    v = {0};
  } else {
    std::sort(v.begin(), v.end());
  }

  v.push_back(v[0] + n);

  int gaps = 0;
  std::vector<int> egaps;
  for (int i = 1; i < v.size(); ++i) {
    int diff = v[i] - v[i-1];
    gaps += diff / 2;
    if (diff % 2 == 0){
      egaps.push_back(diff / 2);
    }
  }

  int bonus = 0;
  std::sort(egaps.begin(), egaps.end());
  for (int e : egaps) {
    int cost = e - 1, gain = e;
    if (y >= cost) {
      x += cost;
      y -= cost;
      gaps -= gain;
      bonus += gain;
    }
  }

  int rem = std::min(y, gaps);
  x += rem;
  bonus += rem;

  return std::max(0LL, x - 2 + bonus);
}

i32safe main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}

