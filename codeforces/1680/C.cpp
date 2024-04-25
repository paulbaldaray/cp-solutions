#include <iostream>
#include <vector>
#include <string>
using uci = int;
#define int long long

inline void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> p(n+1);
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i-1] + s[i-1] - '0';
    }

    int ans = n;
    for (int l = 0, r = p[n]; r <= n; ++l, ++r) {
        ans = std::min(ans, p[n] - p[r] + p[l]);
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
