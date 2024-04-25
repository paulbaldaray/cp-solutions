#include <cstdio>
#include <map>
#include <numeric>
#define NLEFT (n+1)
#define NRIGHT (n+2*(m-l+1))
const int MAX_N = 5e5+10;
int tree[2*MAX_N]{}, N, Q;
 
void update(int i, int x, int n, int l, int r) {
    if (l == r) {
        tree[n] = x;
    } else {
        int m = l+(r-l)/2;
        i <= m ? update(i, x, NLEFT, l, m) : update(i, x, NRIGHT, m+1, r);
        tree[n] = std::gcd(tree[NLEFT], tree[NRIGHT]);
    }
}
 
int query(int lq, int rq, int n, int l, int r) {
    if (rq < l || r < lq || rq < lq) {
        return 0;
    } else if (lq <= l && r <= rq) {
        return tree[n];
    } else {
        int m = l+(r-l)/2;
        return std::gcd(query(lq, rq, NLEFT, l, m), query(lq, rq, NRIGHT, m+1, r));
    }
}
 
int main() {
    scanf("%d", &N);
    for (int i = 1, x; i <= N; ++i) {
        scanf("%d", &x);
        update(i, x, 0, 1, N);
    }
 
    scanf("%d", &Q);
    for (int t, l, r, x, i, y; Q--; ) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d %d", &l, &r, &x);
            int lo = l, hi = r+1;
            while (lo < hi) {
                int mid = lo+(hi-lo)/2;
                if (query(l, mid, 0, 1, N) % x != 0) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            printf("%s\n", std::gcd(query(l, lo-1, 0, 1, N), query(lo+1, r, 0, 1, N)) % x == 0 ? "YES" : "NO");
        } else {
            scanf("%d %d", &i, &y);
            update(i, y, 0, 1, N);
        }
    }
}
