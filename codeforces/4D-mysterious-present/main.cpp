#include <iostream>
#include <vector>
#include <algorithm>
typedef std::pair<int, int> pii;
typedef std::pair<pii, int> piii;
#define F first
#define S second
int main() {
	int n, w, h;
	std::cin >> n >> w >> h;
	std::vector<piii> envs, higher_envs;
	for (int i = 0; i < n; ++i) {
		piii e;
		std::cin >> e.F.F >> e.F.S;
		e.S = i;
		if (w < e.F.F && h < e.F.S)
			envs.push_back(e);
	}
	int high = 0;
	std::vector<int> dp(n, 0), backptr(n, -1);
	std::sort(envs.begin(), envs.end(), std::greater<piii>());
	for (piii &e1 : envs) {
		dp[e1.S] = 1;
		for (piii &e2 : higher_envs)
			if (e1.F.F < e2.F.F && e1.F.S < e2.F.S && dp[e2.S] >= dp[e1.S])
				dp[e1.S] = dp[e2.S]+1, backptr[e1.S] = e2.S;
		if (dp[e1.S] > dp[high])
			high = e1.S;
		higher_envs.push_back(e1);
	}
	std::cout << dp[high] << '\n';
	while (backptr[high] != -1) {
		std::cout << high+1 << ' ';
		high = backptr[high];
	}
	if (!envs.empty())
		std::cout << high+1 << '\n';
}
