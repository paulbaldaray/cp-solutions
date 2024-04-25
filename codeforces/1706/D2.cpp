#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using uci = int;
#define int long long

template <typename T>
std::ostream &operator<<(std::ostream &out, std::vector<T> v) {
  out << "{";
  for (int i = 0; i < v.size(); ++i) {
    std::cout << (i ? "," : "") << v[i];
  }
  return out << "}";
}

std::vector<int> factor(int x, int k, bool s = false) {
  std::vector<int> factors;
  int hi = std::min(k, (int) std::sqrt(x) + 1);
  if (k > x) {
    factors.push_back(0);
  }

  for (int i = 1; i <= hi; ++i) {
    factors.push_back(x / i);
    if (x / i <= k) {
      factors.push_back(i);
    }
    if (x / k == i) {
      factors.push_back(i);
    }
  }

  /* for(int i = x; i > 0;){ */
  /*   factors.push_back(i); */
  /*   int ne = (x/i)+1; */
  /*   i = x/ne; */
  /* } */
  for(int i = x; i > 0;){
    if(x/i <= k) {
      factors.push_back(i);
    }
    if (x / k == i) {
      factors.push_back(i);
    }
    int ne = (x/i)+1;
    i = x/ne;
  }

  /* for (int j = 1; j <= std::min(x, k); j = (x / (x / j)) + 1) { */
  /*   factors.push_back(x / j); */
  /* } */

  std::sort(factors.begin(), factors.end());
  factors.resize(std::distance(factors.begin(), std::unique(factors.begin(), factors.end())));

/*   if (true) { */

/*     std::cout << x << ": " << factors << '\n'; */

/*     std::vector<int> xfactors; */
/*     for (int i = k; i >= 1; --i) { */
/*       if (xfactors.empty() || x / i != xfactors.back()) { */
/*         xfactors.push_back(x / i); */
/*       } */
/*     } */

/*     std::cout << x << ": " << xfactors << '\n'; */
/*   } */


  return factors;
}

int solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end());
  a.resize(std::distance(a.begin(), std::unique(a.begin(), a.end())));
  n = a.size();

  std::vector<int> v(a[0] + 1, 0);

  for (int x : a) {
    int prev = -1;
    /* factor(x, k, true); */
    for (int f : factor(x, k)) {
      v[prev + 1] = std::max(v[prev + 1], f);
      if (f >= a[0]) {
        v[a[0]] = std::max(v[a[0]], f);
        break;
      }
      prev = f;
    }
  }

  int ans = 1e9;
  for (int i = 0, val = 0; i <= a[0]; ++i) {
    val = std::max(val, v[i]);
    ans = std::min(ans, val - i);
  }

  return ans;
}

uci main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}
