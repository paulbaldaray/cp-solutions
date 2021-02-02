#include <iostream>
#include <unordered_map>
int main() {
	int n;
	std::cin >> n;
	std::unordered_map<int, int> index;
	int ans = n;
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		if (index.count(x))
			ans = std::min(ans, i-index[x]);
		index[x] = i;
	}
	std::cout << ans << '\n';
}
