#include <iostream>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T, N, K;
    std::string s;
    std::cin >> T;
    while (T--) {
        std::cin >> N >> K >> s;
        int left = N, right = -1, ans = 0;
        for (int i = 0; i < N; ++i) {
            if (s[i] == '1') {
                if (i == 0) {
                    ans += 10;
                } else if (i == N-1) {
                    ans += 1;
                } else {
                    ans += 11;
                }
                left = std::min(left, i);
                right = std::max(right, i);
            }
        }

        if (left == N || right == -1) {
            std::cout << ans << '\n';
            continue;
        }

        bool onlyone = left == right;
        bool taken = false;
        if (s[N-1] == '0') {
            int cost = N - 1 - right;
            if (onlyone && s[0] == '1') {
                if (cost <= K) {
                    ans += -10 + 1;
                    K -= cost;
                    taken = true;
                }
            } else {
                if (cost <= K) {
                    ans -= 10;
                    K -= cost;
                    taken = true;
                }
            }
        }

        if ((!onlyone || !taken) && s[0] == '0') {
            if (!(onlyone && s[N-1] == '1')) {
                int cost = left;
                if (cost <= K) {
                    ans -= 1;
                    K -= cost;
                }
            }
        }

        std::cout << ans << '\n';
    }
}
