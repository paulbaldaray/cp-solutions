#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
typedef long long LL;
int main() {
	int n;
	std::cin >> n;
	std::map<LL, LL> sorter;
	for (int i = 0, x; i < n; ++i)
		std::cin >> x, ++sorter[x];
	std::vector<LL> nums, val;
	for (auto kv : sorter)
		nums.push_back(kv.first), val.push_back(kv.first*kv.second);
	std::vector<LL> dp(val.size()+2);
	for (int i = val.size()-1; i >= 0; --i) {
		bool next = sorter.count(nums[i]+1);
		dp[i] = std::max(dp[i+1]+(next ? 0 : val[i]), dp[i+2]+val[i]);
	}
	std::cout << std::max(dp[0], dp[1]) << std::endl;
}
