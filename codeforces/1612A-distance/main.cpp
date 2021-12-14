#include <iostream>
#include <cmath>
void solve() {
	int x, y;
	std::cin >> x >> y;
	int z = x + y;
	if (z % 2 == 0) {
		for (int i = 0; i <= z/2; ++i)
			if (std::abs(x-i) + std::abs(y- (z/2 - i)) == z/2) {
				std::cout << i << " " << (z/2 - i) << '\n';
				return;
			}
	}
	std::cout << -1 << " " << -1 << '\n';
}

int main() {
	int T;
	std::cin >> T;
	while (T--)
		solve();
}
