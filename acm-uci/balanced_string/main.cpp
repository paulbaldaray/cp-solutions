#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
int main() {
	std::string s;
	std::cin >> s;
	std::vector<int> idx[256];
	for (char l = 'a', u = 'A'; l <= 'z'; ++l, ++u) {
		idx[l].push_back(s.size());
		idx[u].push_back(s.size());
	}
	for (int i = (int)s.size()-1; i >= 0; --i)
		idx[s[i]].push_back(i);
	int first = 0, last = 0;
	for (int i = 0; i < s.size(); ++i) {
		std::vector<std::pair<int, int>> ranges;
		for (char l = 'a', u = 'A'; l <= 'z'; ++l, ++u) {
			int lo = idx[l].back(), hi = idx[u].back();
			if (lo > hi)
				std::swap(lo, hi);
			if (lo != s.size())
				ranges.push_back({hi, lo});
			if (idx[l].back() == i)
				idx[l].pop_back();
			if (idx[u].back() == i)
				idx[u].pop_back();
		}
		std::sort(ranges.begin(), ranges.end());
		int j = s.size();
		for (int i = (int)ranges.size()-1; i >= 0; --i)
			if (ranges[i].first >= j)
				j = std::min(j, ranges[i].second);
		if (last - first < j - i)
			last = j, first = i;
	}
	std::cout << s.substr(first, last-first) << '\n';
}
