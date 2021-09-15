#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n, m;
	std::string s, p = "abc";
	std::cin >> n >> m >> s;
	std::vector<std::vector<int>> pfxs;
	do {
		pfxs.push_back({0});
		for (int i = 0; i < n; ++i)
			pfxs.back().push_back(pfxs.back().back() + (s[i] != p[i%3]));
	} while(std::next_permutation(p.begin(), p.end()));
	for (int i = 0; i < m; ++i) {
		int ans = 1e9, l, r;
		std::cin >> l >> r;
		for (auto &pfx : pfxs) 
			ans = std::min(ans, pfx[r]-pfx[l-1]);
		std::cout << ans << '\n';
	}
}
