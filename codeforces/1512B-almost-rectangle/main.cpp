#include <iostream>
#include <vector>
#include <string>
void solve() {
	int N;
	std::cin >> N;
	std::vector<std::string> grid(N);
	for (int i = 0; i < N; ++i)
		std::cin >> grid[i];
	int r0, r1, c0, c1, f = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (grid[i][j] == '*') {
				int &r = f ? r1 : r0, &c = f ? c1 : c0;
				r = i, c = j, f = 1;
			}
	if (r0 == r1)
		grid[!r0][c0] = grid[!r0][c1] = '*';
	else if (c0 == c1) {
		grid[r0][!c0] = grid[r1][!c0] = '*';
	} else
		grid[r0][c1] = grid[r1][c0] = '*';
	for (int i = 0; i < N; ++i)
		std::cout << grid[i] << '\n';
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
		solve();
}
