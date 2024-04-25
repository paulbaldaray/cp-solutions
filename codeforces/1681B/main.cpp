#include <iostream>
int a[(int)2e5+10], b[(int)2e5+10];
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    int T, N, M;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
        }
        std::cin >> M;
        for (int i = 0; i < M; ++i) {
            std::cin >> b[i];
        }
        int pos = 0;
        for (int i = M-1; i >= 0; --i) {
            pos = (pos + b[i]) % N;
        }
        std::cout << a[pos] << '\n';
    }
}

/*

---------
1
2
3
4    <-
5

 */
