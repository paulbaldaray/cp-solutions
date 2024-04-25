#include <iostream>
#include <string>
#include <vector>
int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int N, M;
        std::cin >> N >> M;
        std::vector<std::string> grid(N);
        for (int r = 0; r < N; ++r) {
            std::cin >> grid[r];
        }
        int up = N, left = M;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                if (grid[r][c] == 'R') {
                    up = std::min(up, r);
                    left = std::min(left, c);
                }
            }
        }
        bool possible = false;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                if (grid[r][c] == 'R') {
                    if (r == up && c == left) {
                        possible = true;
                    }
                }
            }
        }
        printf("%s\n", possible ? "YES" : "NO");
    }
}
