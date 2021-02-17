#include <iostream>
#include <vector>
int solve() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];
	int ans = 0;
	for (int i = 0; i < n-1; ++i) {
		int hi = std::max(arr[i], arr[i+1]);
		int lo = std::min(arr[i], arr[i+1]);
		while (lo*2 < hi)
			++ans, lo*=2;
	}
	return ans;
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
		std::cout << solve() << '\n';
}
