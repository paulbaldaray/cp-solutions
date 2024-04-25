#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <limits>

using uci = int;
#define int long long
const int inf = std::numeric_limits<int>::max();

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n), d(m), f(k);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> d[i];
    }

    for (int i = 0; i < k; ++i) {
        std::cin >> f[i];
    }

    std::sort(a.begin(), a.end());
    std::sort(d.begin(), d.end());
    std::sort(f.begin(), f.end());

    std::multiset<int> imbas;
    int max_imba = -1, idx = 0;
    for (int i = 1; i < n; ++i) {
        int imba = a[i] - a[i-1];
        if (imba > max_imba) {
            max_imba = imba;
            idx = i - 1;
        }
        imbas.insert(imba);
    }

    d.resize(std::distance(d.begin(), std::unique(d.begin(), d.end())));
    f.resize(std::distance(f.begin(), std::unique(f.begin(), f.end())));
    m = d.size();
    k = f.size();

    imbas.erase(imbas.find(max_imba));
    for (int x : d) {
        const auto cimba = [&](int i) {
            if (i < 0 || i >= k) {
                return inf;
            }
            int v = x + f[i];
            return std::max(std::abs(v - a[idx]), std::abs(a[idx+1] - v));
        };

        int lo = 0, hi = k - 1;
        while (hi - lo > 2) {
            int mid1 = lo + (hi - lo) / 3;
            int mid2 = hi - (hi - lo) / 3;
            if (cimba(mid1) > cimba(mid2)) {
                lo = mid1;
            } else {
                hi = mid2;
            }
        }

        max_imba =
            std::min(
                max_imba,
                std::min(
                    std::min(cimba(lo), cimba(lo+1)),
                    cimba(lo+2)
                )
            );
    }
    imbas.insert(max_imba);

    std::cout << *--imbas.end() << '\n';
}

uci main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
