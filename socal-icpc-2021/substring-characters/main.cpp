#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
typedef long long LL;
bool kmp(const std::string &s, const std::string &p) {
	LL n = s.size(), m = p.size();
	std::vector<LL> lps(m, 0);
	for (LL i = 1, j = 0; i < m; ++i) {
		while (j && p[i] != p[j])
			j = lps[j-1];
		if (p[i] == p[j])
			lps[i] = ++j;
	}
	for (LL i = 0, j = 0; i < n; ++i) {
		while (j && s[i] != p[j])
			j = lps[j-1];
		if (s[i] == p[j])
			++j;
		if (j == m)
			return true;
	}
	return false;
}
const int WSIZE = 150;
LL solve(std::string &s) {
	LL ans = 0;
	std::vector<bool> period(WSIZE);
	for (char c: s)
		period[c] = true;
	std::unordered_set<std::string> words;
	for (int sz = 1; sz < s.size(); ++sz) {
		for (int i = 0; i+sz <= s.size(); ++i) {
			std::string x = s.substr(i, sz);
			std::vector<bool> counts(WSIZE);
			for (char c : x)
				counts[c] = true;
			if (counts != period)
				continue;
			for (auto &p : words)
				if (kmp(x, p))
					goto thingy;
			words.insert(x);
			thingy:;
		}
	}
	return words.size();
}
int main() {
	std::string s;
	while (std::cin >> s)
		std::cout << solve(s) << '\n';
}
