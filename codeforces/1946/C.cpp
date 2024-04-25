#include <iostream>
#include <vector>
using uci = int;
#define int long long

int solve() {
  int n, k;
  std::cin >> n >> k;

  std::vector<std::vector<int>> adj(n+1);
  for (int i = 1, u, v; i <= n - 1; ++i) {
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int low = 1, high = n / k;
  while (low < high) {
    int mid = low + (high - low + 1) / 2;

    int cuts = 0;
    auto dfs = [&](int u, int p, auto dfs) -> int {
      int size = 1;
      for (auto v : adj[u]) {
        if (v != p) {
          int child_size = dfs(v, u, dfs);
          if (child_size < mid) {
            size += child_size;
          } else {
            ++cuts;
          }
        }
      }
      return size;
    };

    int root_size = dfs(1, -1, dfs);
    if (cuts > k || cuts == k && root_size >= mid) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }

  return low;
}

uci main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}
