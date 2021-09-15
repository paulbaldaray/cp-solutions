#include <iostream>
#include <vector>
#include <string>
void solve() {
	int n;
	std::string s;
	std::cin >> n >> s;
	std::vector<bool> haswon(n, false);
	std::vector<std::string> ans(n, std::string(n, 'X'));
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j) {
			if (s[i] == '1' || s[j] == '1')
				ans[i][j] = ans[j][i] = '=';
			else if (!haswon[i])
				ans[i][j] = '+', ans[j][i] = '-', haswon[i] = true;
			else
				ans[i][j] = '-', ans[j][i] = '+', haswon[j] = true;
		}
	for (int i = 0; i < n; ++i)
		if (s[i] == '2' && !haswon[i]) {
			std::cout << "NO\n";
			return;
		}
	std::cout << "YES\n";
	for (auto &x : ans)
		std::cout << x << '\n';
}
int main() {
	int t;
	std::cin >> t;
	while (t--)
		solve();
}
