#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int solve() {
	int D;
	std::cin >> D;
	std::vector<int> diners(D);
	for (int d = 0; d < D; ++d)
		std::cin >> diners[d];
	int hi = *std::max_element(diners.begin(), diners.end()), ans = hi;
	for (int h = 1; h < hi; ++h) {
		int a = 0;
		for (int d : diners)
			a += std::ceil(d/(double)h)-1;
		ans = std::min(ans, a+h);
	}
	return ans;
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t)
		std::cout << "Case #" << t << ": " << solve() << '\n';
}
