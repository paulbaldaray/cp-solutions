#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using LL = long long;

struct SegTree {
	std::vector<int> tree;
	SegTree (int size)
		: tree(4*size+10) {}

	void inc(int n, int l, int r, int i) {
		if (l == r)
			++tree[n];
		else {
			int m = l+(r-l)/2;
			if (i <= m)
				inc(n*2, l, m, i);
			else
				inc(n*2+1, m+1, r, i);
			tree[n] = tree[n*2] + tree[n*2+1];
		}
	};

	int rsq(int n, int l, int r, int lq, int rq) {
		if (r < lq || rq < l || rq < lq)
			return 0;
		else if (lq <= l && r <= rq)
			return tree[n];
		int m = l+(r-l)/2;
		return rsq(n*2, l, m, lq, rq) + rsq(n*2+1, m+1, r, lq, rq);
	}
};

LL solve() {
	LL n, m, k;
	scanf("%lld %lld %lld", &n, &m, &k);
	std::map<LL, LL> xcomp, ycomp;
	std::vector<LL> xs(n), ys(m), xp(k), yp(k);
	for (LL i = 0; i < n; ++i)
		scanf("%lld", &xs[i]), xcomp[xs[i]];
	for (LL i = 0; i < m; ++i)
		scanf("%lld", &ys[i]), ycomp[ys[i]];
	for (LL i = 0; i < k; ++i)
		scanf("%lld %lld", &xp[i], &yp[i]), xcomp[xp[i]], ycomp[yp[i]];
	LL mx = 0, my = 0;
	for (auto &[k, v] : xcomp)
		v = mx++;
	for (auto &[k, v] : ycomp)
		v = my++;
	SegTree xtree(mx), ytree(my);
	std::sort(xs.begin(), xs.end());
	std::sort(ys.begin(), ys.end());
	for (LL i = 0; i < k; ++i) {
		update();
	}
}

int main() {
	LL t;
	scanf("%lld", &t);
	while (t--)
		printf("%lld\n", solve());
}
