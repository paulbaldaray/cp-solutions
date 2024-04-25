#include <iostream>
int main() {
    int T, N;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        int ans = 0;
        for (int i = 0; i < 3; ++i, N /= 10)
            ans += N % 10;
        for (int i = 0; i < 3; ++i, N /= 10)
            ans -= N % 10;
        std::cout << (ans ? "NO" : "YES") << '\n';
    }
}
