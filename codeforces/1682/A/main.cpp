#include <iostream>
int main() {
    int T, N;
    std::cin >> T;
    while (T--) {
        std::string s;
        std::cin >> N >> s;
        int l, r, x;
        if (N % 2) {
            l = N/2-1, r = N/2+1;
        } else {
            l = N/2-1, r = N/2;
        }
        while (l >= 0 && r < N && s[l] == s[r] && s[l] == s[N/2]) {
            --l;
            ++r;
        }
        std::cout << (r-l-1) << '\n';

    }
}
