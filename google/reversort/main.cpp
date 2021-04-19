#include <cstdio>
#include <vector>
#include <algorithm>
int solve() {
	int N;
	std::scanf("%d", &N);
	std::vector<int> v(N);
	for (int i = 0; i < N; ++i)
		std::scanf("%d", &v[i]);
	int cost = 0;
	for (int i = 0; i < N-1; ++i) {
		int j = min_element(v.begin()+i, v.end()) - v.begin();
		cost += j - i + 1;
		std::reverse(v.begin()+i, v.begin()+j+1);
	}
	return cost;
}
int main() {
	int T;
	std::scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
		std::printf("Case #%d: %d\n", t, solve());
}
