#include <cstdio>
#include <algorithm>
int a[(int)1e5+10];
int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int x = 0, y = 0;
        for (int i = 0, z; i < N; ++i) {
            scanf("%d", &a[i]);
            if (a[i] % 2) {
                ++x;
            } else {
                ++y;
            }
        }
        printf("%d\n", std::min(N-x, N-y));
    }
}
