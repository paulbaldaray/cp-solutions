#include <iostream>
int main() {
    int T, N;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        int count = 0, v = ~0;
        for (int i = 0, x; i < N; ++i) {
            std::cin >> x;
            if (x != i) {
                v &= x;
            }
        }
        std::cout << std::min(N, v) << '\n';
    }
}
