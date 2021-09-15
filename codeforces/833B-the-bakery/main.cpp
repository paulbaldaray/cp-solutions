#include <cstdio>
#include <unordered_map>
#include <algorithm>
const int MAX_N = 35e3+10, MAX_K = 50+10, INF = 1e9;
int a[MAX_N], b[MAX_N], dp[MAX_N*4], tree[MAX_N*4], lazy[MAX_N*4];

void build(int n, int l, int r) {
	if (r < l)
		return;
	lazy[n] = 0;
	if (l == r) {
		tree[n] = dp[l];
	} else {
		int m = l+(r-l)/2;
		build(n*2, l, m);
		build(n*2+1, m+1, r);
		tree[n] = std::max(tree[n*2], tree[n*2+1]);
	}
}

void add(int n, int l, int r, int lq, int rq, int v) {
	if (r < lq || rq < l || rq < lq)
		return;
	else if (lq <= l && r <= rq) {
		tree[n] += v;
		lazy[n] += v;
	} else {
		int m = l+(r-l)/2;
		add(n*2, l, m, l, r, lazy[n]);
		add(n*2+1, m+1, r, l, r, lazy[n]);
		lazy[n] = 0;
		add(n*2, l, m, lq, rq, v);
		add(n*2+1, m+1, r, lq, rq, v);
		tree[n] = std::max(tree[n*2], tree[n*2+1]);
	}
}

int query(int n, int l, int r, int lq, int rq) {
	if (r < lq || rq < l || rq < lq)
		return 0;
	else if (lq <= l && r <= rq)
		return tree[n];
	int m = l+(r-l)/2;
	add(n*2, l, m, l, r, lazy[n]);
	add(n*2+1, m+1, r, l, r, lazy[n]);
	lazy[n] = 0;
	return std::max(query(n*2, l, m, lq, rq), query(n*2+1, m+1, r, lq, rq));
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	std::unordered_map<int, int> prev;
	for (int i = n-1; i >= 0; --i) {
		if (prev.count(a[i]))
			b[prev[a[i]]] = i;
		b[i] = -1;
		prev[a[i]] = i;
	}

	for (int i = 0; i <= n; ++i)
		dp[i] = 0;

	for (int j = 1; j <= k; ++j) {
		build(1, 0, n);
		for (int i = 1; i <= n; ++i) {
			add(1, 0, n, b[i-1]+1, i-1, 1);
			dp[i] = query(1, 0, n, 0, i-1);
		}
	}
	printf("%d\n", dp[n]);
}
