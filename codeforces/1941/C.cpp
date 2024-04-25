#include <iostream>
#include <string>
using uci = int;
#define int long long

void solve() {
    int n;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    int ans = 0;
    for (int i = 2; i < s.size(); ++i) {
        std::string p = s.substr(i - 2, 3);
        if (p == "map" || p == "pie") {
            ++ans;
            i += 2;
        }
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
