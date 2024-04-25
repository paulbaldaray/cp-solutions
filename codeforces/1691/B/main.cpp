#include <cstdio>
#include <vector>
int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        std::vector<int> s(N), a(N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &s[i]);
        }

        for (int i = 0, j = 1; i < N; i = j++) {
            while (j < N && s[i] == s[j]) {
                ++j;
            }

            for (int k = i; k < j; ++k) {
                a[k] = i+(k-i+1)%(j-i) + 1;
            }
        }

        bool possible = true;
        for (int i = 0; i < N; ++i) {
            if (a[i] == i+1) {
                possible = false;
            }
        }

        if (possible) {
            for (int i = 0; i < N; ++i) {
                printf("%d ", a[i]);
            }
        } else {
            printf("-1");
        }
        printf("\n");
    }
}
