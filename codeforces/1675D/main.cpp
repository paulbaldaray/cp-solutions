#include <iostream>
#include <vector>
int main() {
    int T, N;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        std::vector<int> p(N+1), is_par(N+1), vis(N+1);
        is_par[0] = vis[0] = true;
        for (int i = 1; i <= N; ++i) {
            std::cin >> p[i];
            if (i == p[i]) {
                p[i] = 0;
            }
            is_par[p[i]] = true;
        }
        std::vector<int> leaves;
        for (int i = 1; i <= N; ++i) {
            if (!is_par[i]) {
                leaves.push_back(i);
            }
        }

        std::cout << leaves.size() << '\n';
        for (auto u : leaves) {
            std::vector<int> path;
            while (!vis[u]) {
                vis[u] = true;
                path.push_back(u);
                u = p[u];
            }
            std::cout << path.size() << '\n';
            for (int i = (int) path.size() - 1; i >= 0; --i) {
                std::cout << path[i] << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}
