#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> solve(int i, int j, int c) {
	if (i == j)
		return {};
	int m = std::min(i+c+1, j);
	auto rec = solve(i+1, m, c-(m-i-1));
	std::reverse(rec.begin(), rec.end());
	rec.push_back(i+1);
	for (; m < j; ++m)
		rec.push_back(m+1);
	return rec;
}

int main() {
	int T, N, C;
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		std::cin >> N >> C;
		std::cout << "Case #" << t << ": ";
		if (C < N-1 || C > (N-1)*(2+N)/2)
			std::cout << "IMPOSSIBLE";
		else
			for (int x : solve(0, N, C-N+1))
				std::cout << x << ' ';
		std::cout << '\n';
	}
}
