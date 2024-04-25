#include <iostream>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        std::string s;
        std::cin >> s;
        int one = 0, zero = (int) s.size() - 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                one = i;
            }
        }
        for (int i = (int) s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                zero = i;
            }
        }
        std::cout << (zero - one + 1) << '\n';
    }
}
