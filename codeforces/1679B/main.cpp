#include <cstdio>
long long a[(int)2e5+10];
long long b[(int)2e5+10];
int main() {
    long long N, Q, t, i, x, s = 0, v = 0, p = 0;
    scanf("%lld %lld", &N, &Q);
    for (i = 1; i <= N; ++i) {
        scanf("%lld", &a[i]);
        s += a[i];
        b[i] = 0;
    }

    while (Q--) {
        scanf("%lld", &t);
        if (t == 1) {
            scanf("%lld %lld", &i, &x);
            if (b[i] == v) {
                s += x - a[i];
            } else {
                s += x - p;
                b[i] = v;
            }
            a[i] = x;
        } else {
            scanf("%lld", &x);
            s = N*x;
            p = x;
            ++v;
        }
        printf("%lld\n", s);
    }
}
