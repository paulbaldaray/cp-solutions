#include <cstdio>
#include <algorithm>
const long long MAX_N = 2e5+10;
long long a[MAX_N], tree[MAX_N*4], n, t;
long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}

void build(int n, int l, int r) {
	if (l >= r)
		tree[n] = l == r ? a[l] : 0;
	else {
		int m = l+(r-l)/2;
		tree[n*2] = tree[n*2+1] = 1;
		build(n*2, l, m);
		build(n*2+1, m+1, r);
		tree[n] = gcd(tree[n*2], tree[n*2+1]);
	}
}

std::pair<long long, int> query(int n, int l, int r, int i, long long g = 0) {
	int m = l+(r-l)/2;
	if (l == r || (l == i && gcd(tree[n], g) != 1))
		return {gcd(tree[n], g), r};
	if (i > m)
		return query(n*2+1, m+1, r, i, g);
	auto left = query(n*2, l, m, i, g);
	if (left.first == 1 || left.second < m)
		return left;
	auto right = query(n*2+1, m+1, r, m+1, left.first);
	return right.first == 1 ? left : right;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int ans = 1;
		for (int i = 0; i < n; ++i)
			scanf("%lld", &a[i]);
		for (int i = 0; i+1 < n; ++i)
			a[i] = a[i] < a[i+1] ? a[i+1] - a[i] : a[i] - a[i+1];
		build(1, 0, n-2);
		for (int i = 0; i < n-1; ++i) {
			auto q = query(1, 0, n-2, i);
			if (q.first != 1)
				ans = std::max(ans, q.second - i + 2);
		}
		printf("%d\n", ans);
	}
}
