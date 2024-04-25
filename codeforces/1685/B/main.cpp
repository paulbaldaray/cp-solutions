#include <cstdio>
#include <algorithm>
using LL = long long;
const LL MAX_N = 1e5+10;
LL p[MAX_N];
int main() {
    LL T, N;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &N);
        for (LL i = 1; i <= N; ++i) {
            scanf("%lld", &p[i]);
        }
        LL ninf = -1e9, hi = ninf, ans = 0;
        for (LL i = 1; i <= N; ++i) {
            if (p[i] < hi) {
                hi = ninf;
                ++ans;
            } else {
                hi = std::max(hi, p[i]);
            }
        }
        printf("%lld\n", ans);
    }
}
