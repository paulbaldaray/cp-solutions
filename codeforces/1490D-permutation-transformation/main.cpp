#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
std::vector<int> solve() {
	int N;
	std::cin >> N;
	std::vector<int> arr(N), depth(N);
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];
	std::function<void (int, int, int)> dfs = [&](int l, int r, int d) {
		if (l == r)
			return;
		int i = std::max_element(arr.begin()+l, arr.begin()+r)-arr.begin();
		depth[i] = d;
		dfs(i+1, r, d+1);
		dfs(l, i, d+1);
	};
	dfs(0, depth.size(), 0);
	return depth;
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		for (int x : solve())
			std::cout << x << ' ';
		std::cout << '\n';
	}
}
