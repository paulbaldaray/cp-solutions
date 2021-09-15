#include <cstdio>
#include <array>
#include <vector>
#include <algorithm>
std::vector<int> tree, lazy;

void update(int n, int l, int r, int lq, int rq, int v) {
	if (r < lq || rq < l || rq < lq) {
		return;
	} else if (lq <= l && r <= rq) {
		tree[n] += v;
		lazy[n] += v;
	} else {
		int m = l+(r-l)/2;
		update(n*2, l, m, l, r, lazy[n]);
		update(n*2+1, m+1, r, l, r, lazy[n]);
		lazy[n] = 0;
		update(n*2, l, m, lq, rq, v);
		update(n*2+1, m+1, r, lq, rq, v);
		tree[n] = std::min(tree[n*2], tree[n*2+1]);
	}
}

int query(int n, int l, int r, int lq, int rq) {
	if (r < lq || rq < l || rq < lq)
		return 1e9;
	else if (lq <= l && r <= rq)
		return tree[n];
	int m = l+(r-l)/2;
	update(n*2, l, m, l, r, lazy[n]);
	update(n*2+1, m+1, r, l, r, lazy[n]);
	lazy[n] = 0;
	tree[n] = std::min(tree[n*2], tree[n*2+1]);
	return std::min(query(n*2, l, m, lq, rq), query(n*2+1, m+1, r, lq, rq));
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	tree.resize(m*4);
	lazy.resize(m*4);
	std::vector<std::array<int, 3>> seg(n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d %d", &seg[i][1], &seg[i][2], &seg[i][0]);
	std::sort(seg.begin(), seg.end());
	int ans = 1e9;
	for (int l = 0, r = 0; r < n; ++r) {
		update(1, 1, m, seg[r][1], seg[r][2]-1, 1);
		for (; query(1, 1, m, seg[l][1], seg[l][2]-1) > 1; ++l)
			update(1, 1, m, seg[l][1], seg[l][2]-1, -1);
		if (query(1, 1, m, 1, m-1))
			ans = std::min(ans, seg[r][0]-seg[l][0]);
	}
	printf("%d\n", ans);
}
