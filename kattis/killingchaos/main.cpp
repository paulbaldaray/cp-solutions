#include <iostream>
#include <vector>
#include <functional>

using LL = long long;

inline LL round10(LL x) {
    return 10 * (x / 10 + (x % 10 > 0));
}

int main() {
    LL n;
    std::cin >> n;
    std::vector<LL> parent(n+2), explosion(n);

    for (LL i = 1; i <= n; ++i)
        std::cin >> parent[i], parent[i] *= -1;

    for (LL i = 0; i < n; ++i)
        std::cin >> explosion[n-i-1];

    std::function<LL (LL)> find = [&](LL u) {
        return parent[u] <= 0 ? u : parent[u] = find(parent[u]);
    };

    std::function<bool (LL, LL)> uni = [&] (LL u, LL v) {
        if (find(u) == find(v))
            return false;
        parent[find(v)] += parent[find(u)];
        parent[find(u)] = find(v);
        return true;
    };

    std::vector<bool> alive(n+2);
    LL segments = 0, total = 0, ans = 0;
    for (LL u : explosion) {
        for (LL v = u-1; v <= u+1; v += 2)
            if (alive[v]) {
                --segments;
                total -= round10(-parent[find(v)]);
                uni(u, v);
            }

        ++segments;
        alive[u] = true;
        total += round10(-parent[find(u)]);
        ans = std::max(ans, segments * total);
    }
    std::cout << ans << '\n';
}
