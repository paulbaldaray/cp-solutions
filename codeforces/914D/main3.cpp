/*
 ___      _    __  __   ____  _    _   _ _____ 
|_ _|    / \  |  \/  | | __ )| |  | | | | ____|
 | |    / _ \ | |\/| | |  _ \| |  | | | |  _|  
 | |   / ___ \| |  | | | |_) | |__| |_| | |___ 
|___| /_/   \_\_|  |_| |____/|_____\___/|_____|
                                               
 _______  ______  _____ ____ _____   _____ ____  _   _ ____ _____ 
| ____\ \/ /  _ \| ____|  _ \_   _| |_   _|  _ \| | | / ___|_   _|
|  _|  \  /| |_) |  _| | |_) || |     | | | |_) | | | \___ \ | |  
| |___ /  \|  __/| |___|  _ < | |     | | |  _ <| |_| |___) || |  
|_____/_/\_\_|   |_____|_| \_\|_|     |_| |_| \_\\___/|____/ |_|  
                                                                  
  ____ _____     _______   __  __ _____    ____  ___   ___  ____  
 / ___|_ _\ \   / / ____| |  \/  | ____|  / ___|/ _ \ / _ \|  _ \ 
| |  _ | | \ \ / /|  _|   | |\/| |  _|   | |  _| | | | | | | | | |
| |_| || |  \ V / | |___  | |  | | |___  | |_| | |_| | |_| | |_| |
 \____|___|  \_/  |_____| |_|  |_|_____|  \____|\___/ \___/|____/ 
                                                                  
  ____ ___  __  __ ____  _   _ _____ _____ ____  
 / ___/ _ \|  \/  |  _ \| | | |_   _| ____|  _ \ 
| |  | | | | |\/| | |_) | | | | | | |  _| | |_) |
| |__| |_| | |  | |  __/| |_| | | | | |___|  _ < 
 \____\___/|_|  |_|_|    \___/  |_| |_____|_| \_\
                                                 
*/
#include <cstdio>
#define NLEFT (n+1)
#define NRIGHT (n+2*(m-l+1))
#define START 0, 1, N
const int MAX_N = 5e5;
int tree[2*MAX_N], N, Q, T, I, Y, L, R, X, LQ, RQ;
 
inline int gcd(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
 
inline void build(int n, int l, int r) {
    int m = l+(r-l)/2;
    if (l == r) {
        scanf("%d", &tree[n]);
    } else {
        build(NLEFT, l, m);
        build(NRIGHT, m+1, r);
        tree[n] = gcd(tree[NLEFT], tree[NRIGHT]);
    }
}
 
inline void update(int n, int l, int r) {
    int m = l+(r-l)/2;
    if (l == r) {
        tree[n] = Y;
    } else {
        I <= m ? update(NLEFT, l, m) : update(NRIGHT, m+1, r);
        tree[n] = gcd(tree[NLEFT], tree[NRIGHT]);
    }
}
 
inline int query(int n, int l, int r) {
    int m = l+(r-l)/2;
    if (RQ < l || r < LQ || RQ < LQ) {
        return 0;
    } else if (LQ <= l && r <= RQ) {
        return tree[n];
    } else {
        return gcd(query(NLEFT, l, m), query(NRIGHT, m+1, r));
    }
}
 
int main() {
    scanf("%d", &N);
    build(START);
 
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &T);
        if (T == 1) {
            scanf("%d %d %d", &L, &R, &X);
            int lo = L, hi = R+1;
            while (lo < hi) {
                int mid = lo+(hi-lo)/2;
                LQ = lo, RQ = mid;
                if (query(START) % X) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
 
            LQ = lo+1, RQ = R;
            if (query(START) % X) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        } else {
            scanf("%d %d", &I, &Y);
            update(START);
        }
    }
}
