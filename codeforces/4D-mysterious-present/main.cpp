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
	std::vector<piii> envs;
	for (int i = 0; i < n; ++i) {
		piii e;
		std::cin >> e.F.F >> e.F.S;
		e.S = i+1;
		if (w < e.F.F && h < e.F.S)
			envs.push_back(e);
	}
	if (envs.empty()) {
		std::cout << 0 << '\n';
		return 0;
	}
	std::sort(envs.begin(), envs.end());
	std::vector<int> dp, bptr(envs.size(), -1), ans;
	for (int i = 0; i < envs.size(); ++i) {
		int l = 0, r = dp.size(), orig = dp.size();
		while (l < r) {
			int m = l + (r-l) / 2;
			if (envs[dp[m]].F.S >= envs[i].F.S)
				r = m;
			else
				l = m + 1;
		}
		bool has_diff_width = !l || envs[dp[l-1]].F.F < envs[i].F.F;
		if (l == dp.size() && has_diff_width)
			dp.push_back(i);
		else if (l < dp.size() && has_diff_width && envs[i].F.S < envs[dp[l]].F.S)
			dp[l] = i;
		bptr[i] = l ? dp[l-1] : -1;
	}
	std::cout << dp.size() << '\n';
	for (int ptr = dp.back(); ptr != -1; ptr = bptr[ptr])
		ans.push_back(envs[ptr].S);
	for (int i = ans.size()-1; i >= 0; --i)
		std::cout << ans[i] << ' ';
	std::cout << '\n';
}

