#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
std::vector<int> solve() {
	int N;
	std::cin >> N;
	std::vector<std::array<int, 2>> players(N);
	for (int i = 0; i < N; ++i)
		std::cin >> players[i][0], players[i][1] = i+1;
	std::sort(players.begin(), players.end());
	auto check = [&](int i) {
		long long score = 0;
		for (int j = 0; j < N; ++j)
			if (j <= i || score >= players[j][0])
				score += players[j][0];
		return score >= players.back()[0];
	};
	int l = 0, r = N;
	while (l < r) {
		int m = l+(r-l)/2;
		if (check(m))
			r = m;
		else
			l = m+1;
	}
	std::vector<int> ans;
	for (int i = l; i < N; ++i)
		ans.push_back(players[i][1]);
	std::sort(ans.begin(), ans.end());
	return ans;
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		auto ans = solve();
		std::cout << ans.size() << '\n';
		for (int x : ans)
			std::cout << x << " ";
		std::cout << '\n';
	}
}
