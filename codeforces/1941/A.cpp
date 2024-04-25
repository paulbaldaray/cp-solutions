#include <iostream>
#include <vector>
#include <algorithm>

using uci = int;
#define int long long

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> left(n), right(m);

    for (int i = 0; i < n; ++i) {
        std::cin >> left[i];
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> right[i];
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end(), std::greater<int>{});
    int ans = 0;
    for (int l = 0, r = 0; r < m; ++r) {
        while (l < n && left[l] + right[r] <= k) {
            ++l;
        }
        ans += l;
    }
    std::cout << ans << '\n';
}

uci main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
