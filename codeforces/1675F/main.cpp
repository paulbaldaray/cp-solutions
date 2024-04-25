#include <iostream>
#include <vector>
using LL = long long;
LL solve() {
    LL N, K, X, Y;
    std::cin >> N >> K >> X >> Y;
    std::vector<std::vector<LL>> adj(N+1);
    std::vector<bool> things(N+1);

    for (LL k = 0, x; k < K; ++k) {
        std::cin >> x;
        things[x] = true;
    }

    for (LL i = 0, u, v; i < N-1; ++i) {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](LL u) -> LL {
        LL found = 0, yfound = false;
        auto f = [&](LL u, LL p, const auto &f) -> LL {
            if (things[u]) {
                ++found;
            }

            if (u == Y) {
                yfound = true;
            }

            LL ans = 0;
            for (LL v : adj[u]) {
                if (v != p) {
                    LL fd = found, yf = yfound;
                    LL value = f(v, u, f);
                    if (fd < found) {
                        ans += value + 1 + (yf == yfound);
                    } else if (yf != yfound) {
                        ans += value + 1;
                    }
                }
            }
            return ans;
        };
        return f(u, -1, f);
    };

    return dfs(X);
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        std::cout << solve() << '\n';
    }
}
