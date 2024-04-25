#include <cstdio>
const int MAX_N = 50 + 10;
int a[MAX_N];
int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        long long sum = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        bool possible = false;
        for (int i = 0; i < N; ++i) {
            if (sum - a[i] == (N-1) * a[i]) {
                possible = true;
            }
        }
        printf("%s\n", possible ? "YES": "NO");
    }
}
