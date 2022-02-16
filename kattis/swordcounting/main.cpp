#include <iostream>
#include <vector>
#include <unordered_set>
#include <array>
using LL = long long;
LL N, M;
std::vector<std::unordered_set<LL>> adj;

inline LL countSwords(LL usz, LL vsz, LL cycles) {
    if (usz < 4)
        return 0;
    LL swords = (usz-1) * (usz-2) * (usz-3) / 6 * (vsz-1);
    return swords - cycles * (usz-2) * (usz-3) / 2;
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    std::cin >> N >> M;
    adj.resize(N, {});
    for (LL i = 0, u, v; i < M; ++i) {
        std::cin >> u >> v;
        adj[u-1].insert(v-1);
        adj[v-1].insert(u-1);
    }

    LL ans = 0;
    auto cpy = adj;
    for (LL u = 0; u < N; ++u)
        while (!cpy[u].empty()) {
            auto v = *cpy[u].begin();
            LL cycles = 0;
            auto &sml = adj[u].size() < adj[v].size() ? adj[u] : adj[v];
            auto &big = adj[u].size() < adj[v].size() ? adj[v] : adj[u];
            for (int w : sml)
                if (big.count(w))
                    ++cycles;
            ans += countSwords(adj[u].size(), adj[v].size(), cycles);
            ans += countSwords(adj[v].size(), adj[u].size(), cycles);
            cpy[u].erase(v);
            cpy[v].erase(u);
        }
    std::cout << ans << '\n';
}
