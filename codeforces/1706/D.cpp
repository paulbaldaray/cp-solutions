#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using uci = int;
#define int long long



int hack = 0;
const int inf = 1e9;

int costWith(
  int floor,
  const std::vector<int> &a,
  int k
){
  int max = -inf, min = inf;
  for (int i = 1; i < a.size(); ++i) {
    int p = std::min((int)k, floor ? a[i] / floor : k);
    int v = 0;
    for (int x = std::min(k, p + 2); x >= std::min(0LL, p - 2); --x) {
      v = x ? a[i] / x : a[i];
      if (v >= floor) {
        break;
      }
    }
    /* int v = p ? a[i] / p : a[i]; */

    /* if (k == 56) { /1* std::cout << v << " "; *1/ } */
    min = std::min(min, v);
    max = std::max(max, v);
  }
  /* if (k == 56) */
  /* std::cout << std::endl; */
  return max - min;
};

bool solve() {
  int n, k;
  std::cin >> n >> k;

  // 1-idx, 1 <= a[i] <= 1e5
  std::vector<int> a(n+1);

  int small = inf, big = -inf;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    small = std::min(small, a[i]);
    big = std::max(big, a[i]);
  }

  a.resize(std::distance(a.begin(), std::unique(a.begin(), a.end())));
  n = a.size();

  //meme
  if (big / k <= 1) {
    std::cout << 0 << '\n';
    return true;
  }

  int delta = 500;

  int low = 0, high = small;
  while (high - low > delta) {
    int mid1 = low + (high - low) / 3;
    int mid2 = high - (high - low) / 3;
    int c1 = costWith(mid1, a, k);
    int c2 = costWith(mid2, a, k);
    // Finding smallest, move the greater
    if (c1 > c2) {
      low = mid1;
    } else {
      high = mid2;
    }
  }

  /* int plow = low, phigh = high, p = -1; */
  /* if (hack == 2) { */
  /*   low = 0; */
  /*   high = small; */
  /* } */

  /* std::vector<int> saved; */
  /* int delta = 2; */
  low = std::max(0LL, low);
  high = std::min(small, high + delta * 3 / 2);
  int ans = inf;
  for (int i = low; i <= high; ++i) {
    /* double x = costWith<double>(i, a, k); */
    int y =  costWith(i, a, k);
    /* if(k == 56)std::cout << i << " " << x << " " << y << '\n'; */
    /* if (1950 <= i && i <= 1960) { */
    /*   saved.push_back(y); */
    /* } */
    /* if (y < ans) { */
    /*   p = i; */
    /* } */
    ans = std::min(ans, y); // costWith<int>(i, a, k));
  }

  /* if (hack == 2 && ans == 1471) { */
  /*   std::cout << p << " " << plow << " " << phigh << '\n'; */
  /*   for (int i = 0; i < saved.size(); ++i) { */
  /*     std::cout << (i + 1950) << ": " << saved[i] << '\n'; */
  /*   } */
  /*   return false; */
  /* } */

  /* if (hack == 2 && ans == 1473) { */
  /*   std::cout << n << " " << k << std::endl; */

  /*   for (int i = 1; i <= n; i += 20) { */
  /*     for (int j = 0; i + j <= n && j < 20; ++j) { */
  /*       std::cout << a[i+j] << ' '; */
  /*     } */
  /*     std::cout << '\n'; */
  /*   } */
  /*   std::cout << std::endl; */
  /*   return false; */
  /* } */
  std::cout << ans << '\n';
  return true;
}

uci main() {
  int t;
  std::cin >> t;
  while (t--) {
    ++hack;
    if (!solve()) {
      return 0;
    }
  }
}
