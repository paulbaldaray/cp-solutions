#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <algorithm>
using LL = long long;
using LL2 = std::array<LL, 2>;
std::vector<LL> fact{1};
LL MOD = 998244353;
LL modPow(LL x, LL e) {
    if (e == 0) {
        return 1;
    }
    LL y = modPow(x, e/2);
    y = (y * y) % MOD;
    return y * (e%2 ? x : 1) % MOD;
}

inline LL invMod(LL a, LL m) {
    return modPow(a, MOD-2);
}

inline LL C(LL n, LL k) {
    return fact[n] * invMod((fact[k] * fact[n-k]) % MOD, MOD) % MOD;
}

#define TLEFT n+1
#define TRIGHT n+2*(m-l+1)
#define TROOT 0, 0, (int)d.size()-1
std::vector<LL> t;
using LL = long long;
void update(const LL &i, LL n, LL l, LL r) {
    if (l == r) {
        ++t[n];
    } else {
        LL m = l+(r-l)/2;
        if (i <= m) { 
            update(i, TLEFT, l, m);
        } else {
            update(i, TRIGHT, m+1, r);
        }
        t[n] = t[TLEFT] + t[TRIGHT];
    }
}

LL query(const LL &lq, const LL &rq, LL n, LL l, LL r) {
    if (rq < l || r < lq || rq < lq) {
        return 0;
    } else if (lq <= l && r <= rq) {
        return t[n];
    } else {
        LL m = l+(r-l)/2;
        return query(lq, rq, TLEFT, l, m) + query(lq, rq, TRIGHT, m+1, r);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    LL N, K;
    std::cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        fact.push_back(i * fact[i-1] % MOD);
    }
    std::vector<LL2> lamps(N);
    std::vector<LL> total(N), points;
    for (LL i = 0, l, r; i < N; ++i) {
        std::cin >> l >> r;
        total[i] = l;
        lamps[i] = {r, l};
        points.push_back(l);
        points.push_back(r);
    }

    std::map<LL, LL> d;
    std::sort(points.begin(), points.end());
    points.resize(std::unique(points.begin(), points.end()) - points.begin());
    for (auto x : points) {
        d[x] = d.size();
    }
    t.assign(2*d.size(), 0);

    std::sort(total.begin(), total.end());
    std::sort(lamps.begin(), lamps.end());
    LL ans = 0;
    for (auto &[r, l] : lamps) {
        auto n = std::upper_bound(total.begin(), total.end(), r) - total.begin();
        update(d[l], TROOT);
        n -= query(0, d[r], TROOT);

        if (n > K-1) {
            ans = (ans + C(n, K-1)) % MOD;
        } else if (n == K-1) {
            ans = (ans + 1) % MOD;
        }

    }
    std::cout << ans << '\n';
}
