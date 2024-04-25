#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
using LL = long long;
using LL2 = std::array<LL, 2>;
int main() {
    LL T, N;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &N);
        std::vector<LL> ans(N);
        for (LL i = 0, x; i < N; ++i) {
            scanf("%lld", &ans[i]);
        }
        std::sort(ans.begin(), ans.end());

        bool possible = true;
        do {
            possible = true;
            for (LL i = 0; i < N; ++i) {
                bool greater = ans[i] > ans[(i-1+N)%N] && ans[i] > ans[(i+1)%N];
                bool lesser = ans[i] < ans[(i-1+N)%N] && ans[i] < ans[(i+1)%N];
                if (!greater && !lesser) {
                    possible = false;
                }
            }

            if (possible) {
                break;
            }

        } while(std::next_permutation(ans.begin(), ans.end()));

        if (possible) {
            printf("YES\n");
            for (LL i = 0; i < N; ++i) {
                printf("%lld ", ans[i]);
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
    }
}
