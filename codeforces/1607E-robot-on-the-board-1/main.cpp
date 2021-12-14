#include <iostream>
#include <array>
#include <string>
int N, M;
std::string s;

std::array<int, 2> possible(int m) {
	int vmin = 0, vmax = 0, hmin = 0, hmax = 0, row = 0, col = 0;
	for (int i = 0; i < m; ++i) {
		switch (s[i]) {
			case 'L':
				--col; break;
			case 'R':
				++col; break;
			case 'D':
				++row; break;
			case 'U':
				--row; break;
		}
		vmin = std::min(vmin, row);
		vmax = std::max(vmax, row);
		hmin = std::min(hmin, col);
		hmax = std::max(hmax, col);
	}
	if (vmax - vmin + 1 > N || hmax - hmin + 1 > M)
		return {-1, -1};
	return {-vmin+1, -hmin+1};
}

void solve() {
	std::cin >> N >> M >> s;
	int l = 0, r = s.size();
	while (l < r) {
		int m = l+(r-l+1)/2;
		if (possible(m) != std::array<int, 2>{-1, -1})
			l = m;
		else
			r = m - 1;
	}
	auto [ar, ac] = possible(l);
	std::cout << ar << " " << ac << '\n';
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	int T;
	std::cin >> T;
	while (T--)
		solve();
}
