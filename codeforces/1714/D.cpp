#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <array>
using uci = int;
#define int long long

void solve() {
    int n;
    std::string t;
    std::cin >> t >> n;
    int m = t.size();
    std::vector<std::string> s(n); // 0-index
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }

    std::array<int, 2> nfar{0, 0};
    std::vector<std::array<int, 2>> far{{0,0}};
    for (int i = 0; i <= m; ++i) {
        if (far.back()[0] < i) {
            if (nfar[0] < i) {
                std::cout << -1 << '\n';
                return;
            }
            far.push_back(nfar);
        }

        if (i == m) {
            break;
        }

        for (int j = 0; j < n; ++j) {
            if (i + s[j].size() > m) {
                continue;
            }
            if (t.substr(i, s[j].size()) == s[j]) {
                nfar = std::max(nfar, {i + (int)s[j].size(), j});
            }
        }
    }

    std::cout << ((int) far.size() - 1) << '\n';
    for (int i = 1; i < far.size(); ++i) {
        auto [e, j] = far[i];
        std::cout << (j+1) << " " << (e - (int)s[j].size() + 1) << '\n';
    }
}

uci main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
