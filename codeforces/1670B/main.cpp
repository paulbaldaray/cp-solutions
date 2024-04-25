#include <iostream>
#include <string>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T, N, K;
    std::string s, c;
    std::cin >> T;
    while (T--) {
        std::cin >> N >> s >> K;
        bool special[26]{};
        for (int i = 0; i < K; ++i) {
            std::cin >> c;
            special[c[0]-'a'] = true;
        }

        int ans = 0, prev = 0;
        for (int i = 0; i < N; ++i) {
            if (special[s[i]-'a']) {
                ans = std::max(ans, i - prev);
                prev = i;
            }
        }
        std::cout << ans << '\n';
    }
}
