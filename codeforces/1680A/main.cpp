#include <cstdio>
int main() {
    int T, l1, l2, r1, r2;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if (r2 < l1 || r1 < l2) {
            printf("%d\n", l1 + l2);
        } else {
            printf("%d\n", l1 <= l2 ? l2 : l1);
        }
    }
}
