#include <iostream>
#include <vector>
#include <string>
#include <set>
using uci = int;
#define int long long

void solve() {
    int n, m, x;
    std::cin >> n >> m >> x;
    std::set<int> curr{x-1}, ncurr;
    while (m--) {
        int r;
        bool clw = false, ccw = false;
        std::cin >> r;
        std::string c;
        std::cin >> c;
        if (c == "0") {
            clw = true;
        } else if (c == "1") {
            ccw = true;
        } else if (c == "?") {
            ccw = clw = true;
        }
        while (!curr.empty()) {
            int z = *curr.begin();
            if (clw) {
                ncurr.insert((z + r) % n);
            }
            if (ccw) {
                ncurr.insert((n + z - r) % n);
            }
            curr.erase(curr.begin());
        }
        std::swap(curr, ncurr);
    }

    std::cout << curr.size() << '\n';
    int count = 0;
    for (int x : curr) {
        std::cout << (x+1);
        if (++count == curr.size()) {
            std::cout << '\n';
        } else {
            std::cout << ' ';
        }
    }
}

uci main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
