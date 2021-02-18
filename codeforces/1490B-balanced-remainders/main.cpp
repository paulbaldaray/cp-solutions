#include <iostream>
int solve() {
	int n;
	std::cin >> n;
	int count[3] = {0}, target = n/3, ans = 0;
	for (int i = 0, x; i < n; ++i)
		std::cin >> x, ++count[x%3];
	for (int i = 0; i < 6; ++i) if (count[i] - target > 0) {
		ans += count[i%3] - target;
		count[(i+1)%3] += count[i%3] - target;
		count[i%3] = target;
	}
	return ans;
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
		std::cout << solve() << '\n';
}
