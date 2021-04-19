#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <array>
typedef std::array<int, 3> Rep;
int onBits (int z) {
	int count = 0;
	for (int i = 0; i < 32; ++i)
		count += !!((1 << i) & z);
	return count;
}
std::string fillPath(Rep a, Rep b) {
	std::string s(32, ' ');
	int last = 0;
	std::vector<int> unused;
	for (int i = 0; i < 32; ++i)
		if ((1 << i) & b[0])
			s[i] = b[1], last = i;
		else
			unused.push_back(i);

	while (unused.back() > last)
		unused.pop_back();

	while (last != 32) {
		for (int i = 0; i < (1 << unused.size()); ++i) {
			int sum = 0;
			for (int j = 0; j < unused.size(); ++j)
					sum += (i & (1<<j)) ? (1<<unused[j]) : -(1<<unused[j]);
			if (sum == a[0]) {
				for (int j = 0; j < unused.size(); ++j)
					s[unused[j]] = (i & (1<<j)) ? a[1] : a[2];
				while (s.back() == ' ')
					s.pop_back();
				return s;
			}
		}
		unused.push_back(++last);
		if (1LL << unused.back() > 2*a[0])
			break;
	}
	return "IMPOSSIBLE";
}
std::string solve() {
	int x, y;
	std::cin >> x >> y;
	Rep a{std::abs(x), 'E', 'W'}, b{std::abs(y), 'N', 'S'};
	if (x < 0)
		std::swap(a[1], a[2]);
	if (y < 0)
		std::swap(b[1], b[2]);
	if (onBits(x) < onBits(y))
		std::swap(a, b);

	std::string s1 = fillPath(a, b), s2 = fillPath(b, a);
	if (s1 == "IMPOSSIBLE" || s2 == "IMPOSSIBLE")
		return s1 == "IMPOSSIBLE" ? s2 : s1;
	return s1.size() < s2.size() ? s1 : s2;
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t)
		std::cout << "Case #" << t << ": " << solve() << '\n';
}
