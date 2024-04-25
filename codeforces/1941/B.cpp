#include <iostream>
#include <vector>

using uci = int;
#define int long long

bool solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            continue;
        } else if (a[i] < 0 || i + 2 > n) {
            return false;
        }
        a[i + 1] -= 2 * a[i];
        a[i + 2] -= a[i];
        a[i] = 0;
    }
    return true;
}

uci main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::cout << (solve() ? "YES" : "NO") << '\n';
    }
}
