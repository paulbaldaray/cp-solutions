#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> nums(n), species(n), ans;
	std::vector<double> ranks(n);
	for (int i = 0; i < n; ++i)
		nums[i] = i, std::cin >> species[i] >> ranks[i];
	std::sort(nums.begin(), nums.end(), [&](int i, int j) {
			return ranks[i] < ranks[j];}
	);
	for (int x : nums) {
		int l = 0, r = ans.size();
		while (l < r) {
			int m = l + (r - l) / 2;
			if (ans[m] > species[x])
				r = m;
			else
				l = m + 1;
		}
		if (l == ans.size())
			ans.push_back(species[x]);
		else if (species[x] < ans[l])
			ans[l] = species[x];
	}
	std::cout << (nums.size() - ans.size()) << '\n';
}
