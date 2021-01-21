#include <iostream>
#include <vector>
#include <algorithm>
#define F first
#define S second
typedef std::pair<int, int> pii;
int calcPat(int col, bool top, bool bot) {
	return top && bot ? 0 : (col%2 ^ top) + 1;
}
bool solve() {
	int N, M;
	std::cin >> N >> M;
	std::vector<pii> blocked(M);
	for (int m = 0; m < M; ++m)
		std::cin >> blocked[m].S >> blocked[m].F; // (c, r)
	std::sort(blocked.begin(), blocked.end());
	int pattern = 0; // 0: ||, 1: _--, 2: --_
	for (int m = 0; m < M; ++m) {
		int row = blocked[m].S, col = blocked[m].F;
		bool top = row == 2, bot = row == 1;
		if (m+1 < M && blocked[m+1].F == col)
			top = bot = true, ++m;
		if (!pattern) {
			pattern = calcPat(col, top, bot);
		} else {
			if (pattern != calcPat(col, bot, top))
				return false;
			pattern = 0;
		}
	}
	return pattern == 0;
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
		std::cout << (solve() ? "YES" : "NO") << '\n';
}
