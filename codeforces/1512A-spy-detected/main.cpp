#include <iostream>
#include <map>
#include <vector>
int solve() {
	int N;
	std::cin >> N;
	std::map<int, std::vector<int>> d;
	for (int i = 1, x; i <= N; ++i) {
		std::cin >> x;
		d[x].push_back(i);
	}
	for (auto &kv : d)
		if (kv.second.size() == 1)
			return kv.second[0];
	return 0;
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
		std::cout << solve() << std::endl;
}
