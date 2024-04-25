#include <iostream>
#include <vector>
#include <utility>

using LL = long long;

LL solve() {
    LL n, q;
    std::cin >> n >> q;
    std::vector<LL> a(n + 1), dp_p(n + 1), dp_n(n + 1);
    for (LL i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    dp_n[0] = dp_p[0] = -1e9;
    LL ans = a[1];
    for (LL i = 1; i <= n; ++i) {
        dp_p[i] = std::max(dp_p[i - 1], std::max(0LL, dp_n[i - 1]) + a[i]);
        dp_n[i] = std::max(dp_n[i - 1], dp_p[i - 1] - a[i]);
        ans = std::max(std::max(ans, dp_p[i]), dp_n[i]);
    }

    return std::max(dp_p[n], dp_n[n]);
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    LL t;
    std::cin >> t;
    while (t--) {
        std::cout << solve() << '\n';
    }
}
