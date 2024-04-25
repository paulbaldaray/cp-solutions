#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

int main() {
    int T, N;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        std::vector<std::array<int, 2>> a(N), b2(N);
        std::vector<int> b(N), b3(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i][0];
            a[i][1] = i;
        }
        for (int i = 0; i < N; ++i) {
            std::cin >> b[i];
        }
        std::sort(a.begin(), a.end());
        for (int i = 0; i < N; ++i) {
            b2[i][0] = b[a[i][1]];
            b2[i][1] = a[i][1];
        }

        for (int i = 0, j = 1; i < N; i = j++) {
            while (j < N && a[i][0] == a[j][0]) {
                ++j;
            }
            std::sort(b2.begin() + i, b2.begin() + j);
        }

        bool possible = true;
        for (int i = 1; i < N; ++i) {
            if (b2[i-1][0] > b2[i][0]) {
                possible = false;
            }
        }

        if (!possible) {
            std::cout << "-1\n";
        } else {
            for (int i = 0; i < N; ++i) {
                b3[b2[i][1]] = i;
            }
            std::vector<std::array<int, 2>> ans;
            for (int i = 0; i < N; ++i) {
                for (int j = i+1; j < N; ++j) {
                    if (b3[j] == i) {
                        std::swap(b3[i], b3[j]);
                        ans.push_back({i+1, j+1});
                        break;
                    }
                }
            }

            std::cout << ans.size() << "\n";
            for (int i = 0; i < ans.size(); ++i) {
                std::cout << ans[i][0] << " " << ans[i][1] << "\n";
            }
        }
    }
}
