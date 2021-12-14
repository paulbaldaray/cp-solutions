#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
bool solve() {
	int N;
	std::cin >> N;
	std::vector<int> v(N), blue, red;
	std::string s;
	for (int i = 0; i < N; ++i)
		std::cin >> v[i];
	std::cin >> s;
	for (int i = 0; i < N; ++i)
		if (s[i] == 'R')
			red.push_back(v[i]);
		else
			blue.push_back(v[i]);
	std::sort(red.begin(), red.end());
	std::sort(blue.begin(), blue.end(), std::greater<int>{});
	std::fill(v.begin(), v.end(), 0);
	for (int i = 1; i <= N; ++i)
		if (!blue.empty() && blue.back() >= i)
			v[i-1] = true, blue.pop_back();
	if (!blue.empty())
		return false;
	for (int i = N; i >= 1; --i)
		if (!v[i-1] && red.back() <= i)
			red.pop_back();
	return red.empty();
}
int main() {
	int T;
	std::cin >> T;
	while (T--)
		std::cout << (solve() ? "YES\n" : "NO\n");
}
