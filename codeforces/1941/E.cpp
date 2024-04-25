#include <iostream>
#include <deque>
#include <vector>
using uci = int;
#define int long long


#define TMID (tl + (tr - tl) / 2)
#define TLEFT (tn + 1)
#define TRIGHT (tn + 2 * (TMID - tl + 1))

const int inf = 4e15;

struct SegTree {
    int n;
    std::vector<int> tree;
    SegTree(int n) : n{n}, tree(2*n-1) {}
    int min(int lq, int rq) { return min(lq, rq, 0, 1, n); }
    int min(int lq, int rq, int tn, int tl, int tr) {
        if (rq < tl || tr < lq || rq < lq) {
            return inf;
        } else if (lq <= tl && tr <= rq) {
            return tree[tn];
        } else {
            return std::min(
                    min(lq, rq, TLEFT, tl, TMID),
                    min(lq, rq, TRIGHT, TMID + 1, tr)
                );
        }
        return 0;
    }
    void update(int i, int v) { update(i, v, 0, 1, n); }
    void update(int i, int v, int tn, int tl, int tr) {
        if (tl == tr) {
            tree[tn] = v;
        } else {
            if (i <= TMID) {
                update(i, v, TLEFT, tl, TMID);
            } else {
                update(i, v, TRIGHT, TMID + 1, tr);
            }
            tree[tn] = std::min(tree[TLEFT], tree[TRIGHT]);
        }
    }
};

int minCost(const std::vector<int> &v, int m, int d) {
    SegTree dp(m);
    dp.update(1, v[1] + 1);
    int last = 0;
    for (int i = 2; i <= m; ++i) {
        last = dp.min(std::max(1LL, i-d-1), i-1) + v[i] + 1;
        dp.update(i, last);
    }
    return last;
}

void solve() {
    int n, m, k, d;
    std::cin >> n >> m >> k >> d;
    int curr = 0, ans = inf;
    std::vector<int> rcost, v(m+1);
    std::deque<int> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> v[j];
        }
        q.push_back(minCost(v, m, d));
        curr += q.back();
        if (q.size() > k) {
            curr -= q.front();
            q.pop_front();
        }
        if (q.size() == k) {
            ans = std::min(ans, curr);
        }
    }
    std::cout << ans << '\n';
}

uci main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}

