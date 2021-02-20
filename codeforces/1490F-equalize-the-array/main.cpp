#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
typedef long long LL;
LL solve() {
	int N;
	std::cin >> N;
	std::map<int, int> count;
	for (int i = 0, x; i < N; ++i)
		std::cin >> x, ++count[x];
	int n = count.size();
	std::vector<int> freq;
	for (auto &kv : count)
		freq.push_back(kv.second);
	std::sort(freq.begin(), freq.end());
	std::vector<LL> pfx(1, 0);
	for (int x : freq)
		pfx.push_back(x+pfx.back());
	LL ans = 1e18;
	for (int i = 0; i < n; ++i)
		ans = std::min(ans, pfx[i]+pfx[n]-pfx[i+1]-freq[i]*(n-i-1));
	return ans;
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
		std::cout << solve() << '\n';
}
