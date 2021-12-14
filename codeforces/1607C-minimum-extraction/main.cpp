#include <iostream>
#include <vector>
#include <algorithm>
void solve() {
	int N;
	std::cin >> N;
	std::vector<int> a(N);
	for (int i = 0; i < N; ++i)
		std::cin >> a[i];
	std::sort(a.begin(), a.end());
	int add = 0, ans = a[0];
	for (int x : a) {
		ans = std::max(ans, add + x);
		add -= x + add;
	}
	std::cout << ans << '\n';
}
int main() {
	int T;
	std::cin >> T;
	while (T--)
		solve();
}
