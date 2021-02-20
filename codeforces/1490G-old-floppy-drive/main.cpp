#include <cstdio>
#include <vector>
typedef long long LL;
void solve() {
	LL N, M;
	std::scanf("%lld %lld", &N, &M);
	std::vector<LL> cmax(1);
	std::scanf("%lld", &cmax[0]);
	LL total = cmax[0];
	for (LL i = 1, x; i < N; ++i) {
		std::scanf("%lld", &x);
		total += x;
		cmax.push_back(std::max(cmax.back(), total));
	}
	for (LL i = 0, x; i < M; ++i) {
		std::scanf("%lld", &x);
		LL l = 0, r = 1e9/total+5;
		LL row = 0;
		while (total > 0 && l < r) {
			LL m = l+(r-l)/2;
			if (m*total + cmax[N-1] >= x)
				r = m;
			else
				l = m+1;
			row = l;
		}
		l = 0, r = N, x -= row*total;
		while (l < r) {
			LL m = l+(r-l)/2;
			if (cmax[m] >= x)
				r = m;
			else
				l = m+1;
		}
		LL col = l;
		std::printf("%lld ", (col == N ? -1 : row*N + col));
	}
	std::printf("\n");
}
int main() {
	LL T;
	std::scanf("%lld", &T);
	for (LL t = 0; t < T; ++t)
		solve();
}
