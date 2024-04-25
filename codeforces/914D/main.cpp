#include <cstdio>
#include <algorithm>
#define TLEFT (n+1)
#define TRIGHT (n+2*(m-l+1))
#define TSTART 0, 1, N
int tree[(int)1e6], N, Q, T, I, Y, L, R, X;

int gcd(int a, int b) {
    while (b) {
        std::swap(a %= b, b);
    }
    return a;
}

void build(int n, int l, int r) {
    if (l == r) {
        scanf("%d", &tree[n]);
    } else {
        int m = l+(r-l)/2;
        build(TLEFT, l, m);
        build(TRIGHT, m+1, r);
        tree[n] = gcd(tree[TLEFT], tree[TRIGHT]);
    }
}

void update(int n, int l, int r) {
    if (l == r) {
        tree[n] = Y;
    } else {
        int m = l+(r-l)/2;
        I <= m ? update(TLEFT, l, m) : update(TRIGHT, m+1, r);
        tree[n] = gcd(tree[TLEFT], tree[TRIGHT]);
    }
}

inline int query(int n, int l, int r) {
    if (R < l || r < L || R < L) {
        return 0;
    } else if (l == r || tree[n] % X == 0) {
        return tree[n] % X != 0;
    } else {
        int m = l+(r-l)/2, left = 0, right = 0;
        if ((left = query(TLEFT, l, m)) <= 1) {
            right = query(TRIGHT, m+1, r);
        }
        return left + right;
    }
}

int main() {
    scanf("%d", &N);
    build(TSTART);

    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &T);
        if (T == 1) {
            scanf("%d %d %d", &L, &R, &X);
            printf("%s\n", query(TSTART) <= 1 ? "YES" : "NO");
        } else {
            scanf("%d %d", &I, &Y);
            update(TSTART);
        }
    }
}
