#include <iostream>
#include <vector>
#include <utility>

using uci = int;
#define int long long

#define TMID (tl + (tr - tl) / 2)
#define TLEFT (tn + 1)
#define TRIGHT (tn + 2 * (TMID - tl + 1))

struct Seq {
    int pp = 0, nn = 0, pn = 0, np = 0;
    Seq() = default;
    Seq(int x) : pp{x}, nn{-x} {}
    Seq(int pp, int nn, int pn, int np) : pp{pp}, nn{nn}, pn{pn}, np{np} {}
    int max() { return pp; }
    Seq operator+(const Seq &r) const {
        return Seq(
            std::max(pp + r.np, pn + r.pp),
            std::max(nn + r.pn, np + r.nn),
            std::max(pp + r.nn, pn + r.pn),
            std::max(nn + r.pp, np + r.np)
        );
    }
};

template <typename T>
struct SegTree {
    int n;
    std::vector<T> tree;
    SegTree(int n) : n{n}, tree(2*n-1) {}
    int max() { return tree[0].max(); }
    void update(int i, const T &v) { update(i, v, 0, 1, n); }
    void update(int i, const T &v, int tn, int tl, int tr) {
        if (tl == tr) {
            tree[tn] = v;
        } else {
            if (i <= TMID) {
                update(i, v, TLEFT, tl, TMID);
            } else {
                update(i, v, TRIGHT, TMID + 1, tr);
            }
            tree[tn] = tree[TLEFT] + tree[TRIGHT];
        }
    }
};

void solve() {
    int n, q;
    std::cin >> n >> q;
    SegTree<Seq> tree(n);
    std::vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        tree.update(i, a[i]);
    }
    std::cout << tree.max() << '\n';
    for (int lq, rq; q--;) {
        std::cin >> lq >> rq;
        std::swap(a[lq], a[rq]);
        tree.update(lq, a[lq]);
        tree.update(rq, a[rq]);
        std::cout << tree.max() << '\n';
    }
}

uci main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}

