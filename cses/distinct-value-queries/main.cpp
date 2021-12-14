#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
const int MAX_N = 2e5+10;
int prev[MAX_N];
std::unordered_map<int, int> occ;
std::vector<int> tree[4*MAX_N];
void build(int n, int l, int r) {
	if (l == r)
		tree[n].push_back(prev[l]);
	else {
		int m = l+(r-l)/2;
		build(n*2, l, m);
		build(n*2+1, m+1, r);
		tree[n].resize(r-l+1);
		std::merge(tree[n*2].begin(), tree[n*2].end(),
				tree[n*2+1].begin(), tree[n*2+1].end(), tree[n].begin());
	}
}

int query(int lq, int rq, int n, int l, int r) {
	if (r < lq || rq < l)
		return 0;
	else if (lq <= l && r <= rq)
		return std::lower_bound(tree[n].begin(), tree[n].end(), lq) - tree[n].begin();
	int m = l+(r-l)/2;
	return query(lq, rq, n*2, l, m) + query(lq, rq, n*2+1, m+1, r);
}

int main() {
	int n, q, a, b;
	scanf("%d %d", &n, &q);
	occ.reserve(MAX_N);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		prev[i] = occ[x];
		occ[x] = i;
	}
	build(1, 1, n);
	while (q--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", query(a, b, 1, 1, n));
	}
}
