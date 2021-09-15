#include <vector>
#include <string>
#include <iostream>
int main() {
	int T;
	std::cin >> T;
	while (T--) {
		std::string a, b;
		std::cin >> a >> b;
		std::vector<std::vector<int>> dp(a.size()+1, std::vector<int>(b.size()+1));
		int ans = 0;
		for (int i = 1; i <= a.size(); ++i)
			for (int j = 1; j <= b.size(); ++j)
				if (a[i-1] == b[j-1])
					ans = std::max(ans, dp[i][j] = dp[i-1][j-1]+1);
		std::cout << (b.size()+a.size()-ans*2) << '\n';
	}
}
