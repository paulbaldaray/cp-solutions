#include <iostream>
#include <vector>
#include <utility>

using LL = long long;

#define TMID (tl + (tr - tl) / 2)
#define TLEFT (tn + 1)
#define TRIGHT (tn + 2 * (TMID - tl + 1))

struct Seq {
    LL pp = 0, nn = 0, pn = 0, np = 0;
    Seq() = default;
    Seq(LL x) : pp{x}, nn{-x} {}
    Seq(LL pp, LL nn, LL pn, LL np) : pp{pp}, nn{nn}, pn{pn}, np{np} {}
    LL max() { return pp; };
    Seq operator+(const Seq &r) const {
        return Seq(
                std::max(pn + r.pp, pp + r.np),
                std::max(np + r.nn, nn + r.pn),
                std::max(pn + r.pn, pp + r.nn),
                std::max(nn + r.pp, np + r.np)
            );
    }
};

template <typename T>
struct SegTree {
    LL n;
    std::vector<T> tree;
    SegTree(LL n) : n{n}, tree(2*n-1) {}

    LL max() { return tree[0].max(); }

    inline void update(int i, const T &x) { update(i, x, 0, 1, n); }
    void update(const int i, const T &x, LL tn, LL tl, LL tr) {
        if (tl == tr) {
            tree[tn] = x;
        } else {
            if (i <= TMID) {
                update(i, x, TLEFT, tl, TMID);
            } else {
                update(i, x, TRIGHT, TMID + 1, tr);
            }
            tree[tn] = tree[TLEFT] + tree[TRIGHT];
        }
    }
};

LL solve() {
    LL n, q;
    std::cin >> n >> q;
    SegTree<Seq> tree(n);
    std::vector<LL> a(n+1);

    for (LL i = 1; i <= n; ++i) {
        std::cin >> a[i];
        tree.update(i, a[i]);
    }
    std::cout << tree.max() << '\n';

    for (LL lq, rq; q--;) {
        std::cin >> lq >> rq;
        std::swap(a[lq], a[rq]);
        tree.update(lq, a[lq]);
        tree.update(rq, a[rq]);
        std::cout << tree.max() << '\n';
    }
    return 0LL;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
