#include <iostream>
#include <cmath>
#include <vector>
#include <string>
int main() {
    int T, N, M;
    std::cin >> T;
    while (T--) {
        std::cin >> N >> M;
        std::vector<std::string> v(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> v[i];
        }
        int ans = 1e9;
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                int dist = 0;
                for (int k = 0; k < M; ++k) {
                    dist += std::abs(v[i][k] - v[j][k]);
                }
                ans = std::min(ans, dist);
            }
        }
        std::cout << ans << '\n';
    }
}
