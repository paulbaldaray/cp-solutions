#include <iostream>
#include <string>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while (T--) {
        int a, b, ab, ba;
        std::string s;
        std::cin >> a >> b >> ab >> ba;
        std::cin >> s;
        for (int i = 0; i < s.size();) {
            if (i+1 < s.size() && s[i] != s[i+1]) {
                if (i+2 < s.size() && s[i] == s[i+2]) {
                    if (ab > ba) {
                    }
                } else if (s[i] == 'A' && ab) {
                    --ab;
                    i += 2;
                } else if (s[i] == 'B' && ba) {
                    --ba;
                    i += 2;
                } else if (s[i] == 'A') {
                    --a;
                    i += 1;
                } else {
                    --b;
                    i += 1;
                }
            } else if (s[i] == 'A') {
                --a;
                i += 1;
            } else {
                --b;
                i += 1;
            }
        }

        if (a || b || ab || ba) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
}
