#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using LL = long long;
using LL2 = std::array<LL, 2>;
std::map<LL, LL> count;
std::map<LL, std::set<LL>> counts;
LL getHighestCount() {
    while (!counts.empty()) {
        if (!counts.rbegin()->second.empty()) {
            return *counts.rbegin()->second.begin();
        }

        counts.erase(counts.rbegin()->first);
    }
    return -1;
}

int main() {
    LL T, N;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &N);
        counts.clear();
        count.clear();
        for (LL i = 0, x; i < N; ++i) {
            scanf("%lld", &x);
            ++count[x];
        }

        std::set<LL> s;
        for (auto [k, v] : count) {
            counts[v].insert(k);
            s.insert(k);
        }

        std::vector<LL> ans;
        while (!s.empty()) {
            if (s.size() == 1) {
                if (count[*s.begin()] == 1) {
                    ans.push_back(*s.begin());
                }
                break;
            } else {
                LL a = *s.begin(), b;
                s.erase(a);
                counts[count[a]].erase(a);
                if (count[a] == 1) {
                    LL x = *s.begin();
                    s.erase(x);
                    counts[count[x]].erase(x);

                    b = getHighestCount();
                    s.insert(x);
                    counts[count[x]].insert(x);
                    if (b == -1) {
                        b = x;
                    }
                } else {
                    b = getHighestCount();
                }

                s.erase(b);
                counts[count[b]].erase(b);

                ans.push_back(a);
                ans.push_back(b);

                if (--count[b]) {
                    s.insert(b);
                    counts[count[b]].insert(b);
                }

                if (--count[a]) {
                    s.insert(a);
                    counts[count[a]].insert(a);
                }
            }
        }

        bool possible = ans.size() == N;
        for (LL i = 0; possible && i < N; ++i) {
            bool greater = ans[i] > ans[(i-1+N)%N] && ans[i] > ans[(i+1)%N];
            bool lesser = ans[i] < ans[(i-1+N)%N] && ans[i] < ans[(i+1)%N];
            if (!greater && !lesser) {
                possible = false;
            }
        }

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
