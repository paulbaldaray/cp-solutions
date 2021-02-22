#include <cstdio>
void solve() {
	int N, weakest = 1e9, count = 0;
	std::scanf("%d", &N);
	for (int i = 0, x; i < N; ++i) {
		std::scanf("%d", &x);
		if (x < weakest)
			weakest = x, count = 1;
		else if (x == weakest)
			++count;
	}
	std::printf("%d\n", N-count);
}
int main() {
	int T;
	std::scanf("%d", &T);
	for (int t = 0; t < T; ++t)
		solve();
}
