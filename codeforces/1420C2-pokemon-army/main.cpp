#include <cstdio>
#include <vector>
#include <algorithm>

using LL = long long;
const LL INF = 1e9;

struct Value {
	LL pp, pn, np, nn;
	Value (LL pp = -INF, LL pn = -INF, LL np = -INF, LL nn = -INF)
		: pp{pp}, pn{pn}, np{np}, nn{nn} {}
	LL max() {
		return std::max({pp, pn, np, nn});
	}
};

struct Node {
	int left = 0, right = 0;
	Value v = {};
};

Value join(Value l, Value r) {
	return Value(
		std::max({l.pp, r.pp, l.pp + r.np, l.pn + r.pp}),
		std::max({l.pn, r.pn, l.pn + r.pn, l.pp + r.nn}),
		std::max({l.np, r.np, l.np + r.np, l.nn + r.pp}),
		std::max({l.nn, r.nn, l.nn + r.pn, l.np + r.nn})
	);
};

struct SegTree {
	std::vector<Node> tree = {{}, {}};
	void visit(int n, int l, int m, int r) {
		if (!tree[n].left && l <= m)
			tree[n].left = tree.size(), tree.push_back({});
		if (!tree[n].right && m+1 <= r)
			tree[n].right = tree.size(), tree.push_back({});
	}

	void update(int n, int l, int r, int i, int v) {
		if (l == r)
			tree[n].v = {v, -INF, -INF, -v};
		else {
			int m = l + (r-l)/2; 
			visit(n, l, m, r);
			if (i <= m)
				update(tree[n].left, l, m, i, v);
			else
				update(tree[n].right, m+1, r, i, v);
			tree[n].v = join(tree[tree[n].left].v, tree[tree[n].right].v);
		}
	}
};

int main() {
	int t, n, q;
	scanf("%d", &t);
	std::vector<int> pokemon;
	while (t--) {
		scanf("%d %d", &n, &q);
		pokemon.resize(n+1);
		SegTree tree;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &pokemon[i]);
			tree.update(1, 1, n, i, pokemon[i]); }
		for (int i = 0, x, y; i <= q; ++i) {
			printf("%lld\n", tree.tree[1].v.max());
			if (i != q) {
				scanf("%d %d", &x, &y);
				std::swap(pokemon[x], pokemon[y]);
				tree.update(1, 1, n, x, pokemon[x]);
				tree.update(1, 1, n, y, pokemon[y]);
			}
		}
	}
}
