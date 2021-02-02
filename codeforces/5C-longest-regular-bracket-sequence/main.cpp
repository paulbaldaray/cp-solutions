#include <iostream>
#include <vector>
#include <string>
int main() {
	std::string s;
	std::cin >> s;
	int n = s.size(), ans = 0, count = 0;
	std::vector<int> dp(n+1), stack;
	for (int i = 1; i <= n; ++i) {
		if (s[i-1] == '(')
			stack.push_back(i), dp[i] = i;
		else if (!stack.empty())
			dp[i] = dp[stack.back()-1], stack.pop_back();
		else
			dp[i] = i;
	 if (i-dp[i] == ans)
			++count;
		else if (i-dp[i] > ans) 
			ans = i-dp[i], count = 1;
	}
	std::cout << ans << ' ' << (ans ? count : 1) << '\n';
}
