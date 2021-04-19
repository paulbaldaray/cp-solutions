#include <iostream>
#include <string>
void solve() {
	int a, b, n;
	std::cin >> a >> b;
	std::string s;
	std::cin >> s;
	n = s.size();
	for (char c : s)
		if (c != '?')
			--(c == '0' ? a : b);
	for (int i = 0; i < n/2; ++i) {
		if ((s[i] =='?') ^ (s[n-1-i] == '?')) {
			char &q = s[i] == '?' ? s[i] : s[n-1-i];
			char &c = s[i] != '?' ? s[i] : s[n-1-i];
			if (c == '0')
				q = '0', --a;
			else if (c == '1')
				q = '1', --b;
		}
	}
	for (int i = 0; i < n/2; ++i)
		if (s[i] == '?') {
			if (a > b)
				a -= 2, s[i] = s[n-1-i] = '0';
			else
				b -= 2, s[i] = s[n-1-i] = '1';
		}
	if (n&1 && s[n/2] == '?') {

		if (a > b)
			--a, s[n/2] = '0';
		else
			--b, s[n/2] = '1';
	}
	bool valid = a == 0 && b == 0;
	for (int i = 0; i < n/2; ++i)
		valid &= s[i] == s[n-1-i];
	if (valid)
		std::cout << s << '\n';
	else
		std::cout << -1 << '\n';
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
		solve();
}
