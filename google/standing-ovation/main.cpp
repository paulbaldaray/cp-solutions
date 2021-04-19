#include <iostream>
#include <string>

int solve() {
	std::string s;
	std::cin >> s >> s;
	int people = 0, friends = 0;
	for (int i = 0; i < s.size(); ++i) {
		int v = s[i]-'0';
		if (friends+people < i)
			friends = i-people;
		people += v;
	}
	return friends;
}

int main() {
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t)
		std::cout << "Case #" << t << ": " << solve() << '\n';
}
