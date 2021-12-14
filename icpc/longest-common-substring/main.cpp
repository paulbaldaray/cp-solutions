#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
int main() {
	int N;
	std::cin >> N;
	std::string s, p;
	std::cin >> p;
	std::vector<std::pair<int, int>> subs;
	for (int sz = 1; sz <= p.size(); ++sz)
		for (int i = 0; i+sz <= p.size(); ++i)
			subs.push_back({i, sz});
	std::vector<int> lps(p.size());
	for (int n = 0; n < N-1; ++n) {
		std::cin >> s;
		std::vector<std::pair<int, int>> next;
		while (!subs.empty()) {
			int st = subs.back().first, sz = subs.back().second;
			subs.pop_back();
			std::fill(lps.begin(), lps.begin()+sz, 0);
			for (int i = 1, j = 0; i < sz; ++i) {
				while (j && p[i+st] != p[j+st])
					j = lps[j-1];
				if (p[i+st] == p[j+st])
					lps[i] = ++j;
			}
			for (int i = 0, j = 0; i < s.size(); ++i) {
				while (j && s[i] != p[j+st])
					j = lps[j-1];
				if (s[i] == p[j+st])
					++j;
				if (j == sz) {
					next.push_back({st, sz});
					break;
				}
			}
		}
		subs = move(next);
	}
	int ans = 0;
	for (auto &x : subs)
		ans = std::max(ans, x.second);
	std::cout << ans << '\n';
}
