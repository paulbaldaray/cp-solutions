#include <iostream>
#include <vector>
#include <string>
int main() {
    int T;
    std::cin >> T;
    while (T--) {
        std::string s;
        std::cin >> s;
        std::vector<int> oneleft(s.size()+1), oneright(s.size());

        for (int i = 1; i <= s.size(); ++i) {
            oneleft[i] = oneleft[i-1] + (s[i-1] == '1');
        }
        for (int i = (int)s.size()-2; i >= 0; --i) {
            oneright[i] = oneright[i+1] + (s[i+1] == '1');
        }

        int lo = 0, hi = s.size() + 1, ans = 1e9;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool possible = false;
            for (int l = 0, r = 0, z = 0; r < s.size(); ++r) {
                z += s[r] == '0';
                while (z > mid) {
                    z -= s[l++] == '0';
                }
                possible |= oneleft[l] + oneright[r] <= mid;
            }
            if (possible)
                hi = mid;
            else
                lo = mid + 1;
        }
        printf("%d\n", lo);
    }
}
