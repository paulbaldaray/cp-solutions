#include <iostream>
int a[1000];
int main() {
    int T, N;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        int small = 1e9;
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
            small = std::min(a[i], small);
        }
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += a[i] - small;
        }
        std::cout << ans << '\n';
    }
}
