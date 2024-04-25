#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#define TLEFT n+1
#define TRIGHT n+2*(m-l+1)
#define TROOT 0, 0, N
using LL = long long;
const LL NINF = std::numeric_limits<LL>::min();
const LL MAX_N = 2e5 + 10;
LL T, N, a[MAX_N], pfx[MAX_N], t[2*MAX_N];
void build(LL n, LL l, LL r) {
    if (l == r) {
        t[n] = pfx[l];
    } else {
        LL m = l+(r-l)/2;
        build(TLEFT, l, m);
        build(TRIGHT, m+1, r);
        t[n] = std::max(t[TLEFT], t[TRIGHT]);
    }
}

LL query(const LL &lq, const LL &rq, LL n, LL l, LL r) {
    if (rq < l || r < lq || rq < lq) {
        return NINF;
    } else if (lq <= l && r <= rq) {
        return t[n];
    } else {
        LL m = l+(r-l)/2;
        return std::max(query(lq, rq, TLEFT, l, m), query(lq, rq, TRIGHT, m+1, r));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    while (T--) {
        std::cin >> N;

        for (LL i = 0; i < N; ++i) {
            std::cin >> a[i];
        }

        bool possible = true;
        for (LL flip = 0; flip < 2; ++flip) {
            std::reverse(a, a+N);

            pfx[0] = 0;
            for (LL i = 0; i < N; ++i) {
                pfx[i+1] = pfx[i] + a[i];
            }

            build(TROOT);
            std::vector<LL> s, right(N);

            for (LL i = N-1; i >= 0; --i) {
                while (!s.empty() && a[s.back()] <= a[i]) {
                    s.pop_back();
                }
                right[i] = s.empty() ? N : s.back();
                s.push_back(i);
            }

            for (LL i = 0; i < N; ++i) {
                LL x = query(i+1, right[i], TROOT);
                if (x == NINF)
                    continue;
                if (x - pfx[i+1] > 0) {
                    possible = false;
                }
            }
        }

        if (possible) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}
