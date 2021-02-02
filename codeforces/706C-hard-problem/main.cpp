#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long LL;
int main() {
	int n;
	std::cin >> n;
	std::vector<int> costs(n);
	for (int i = 0; i < n; ++i)
		std::cin >> costs[i];
	std::vector<std::string> words(2*n);
	for (int i = 0; i < n; ++i) {
		std::cin >> words[i];
		words[n+i] = words[i];
		std::reverse(words[n+i].begin(), words[n+i].end());
	}
	auto valif = [&](int i, int j, LL val, LL incr = 0)->LL {
		return words[i] <= words[j] ? val + incr : 1e17;
	};
	LL rev = costs[0], norev = 0;
	for (int i = 1; i < n; ++i) {
		LL rev1 = rev, norev1 = norev;
		norev = std::min(valif(i-1, i, norev1), valif(n+i-1, i, rev1));
		rev = std::min(valif(i-1, n+i, norev1, costs[i]), valif(n+i-1, n+i, rev1, costs[i]));
		if (rev >= 1e17 && norev >= 1e17) {
			rev = norev = -1;
			break;
		}
	}
	std::cout << std::min(rev, norev) << '\n';

}
