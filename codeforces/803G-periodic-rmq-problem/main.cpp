#include <cstdio>
#include <limits>
#include <unordered_map>
struct Node {
	int value, lazy, init;
	Node (int value = 2e9, int lazy = -1, int init = false)
		: value{value}, lazy{lazy}, init{init} {}
};

Node join(Node n1, Node n2) {
	return Node(std::min(n1.value, n2.value), -1, true);
}

struct SegTree {
	int lbound, rbound;
	SegTree *btree;
	std::unordered_map<int, Node> tree;

	SegTree(int lbound, int rbound, SegTree *btree = nullptr)
		: lbound{lbound}, rbound{rbound}, btree{btree} {
	}

	void update(int n, int l, int r, int lq, int rq, int v) {
		if (r < lq || rq < l || rq < lq) {
			updateBackup(n, l, r);
		} else if (lq <= l && r <= rq) {
			tree[n] = Node(v, v, true);
		} else {
			int m = l+(r-l)/2;
			if (tree[n].lazy != -1) {
				update(n*2, l, m, l, r, tree[n].lazy);
				update(n*2+1, m+1, r, l, r, tree[n].lazy);
			}
			update(n*2, l, m, lq, rq, v);
			update(n*2+1, m+1, r, lq, rq, v);
			tree[n] = join(tree[n*2], tree[n*2+1]);
		}
	}

	void updateBackup(int n, int l, int r) {
		if (btree == nullptr || tree[n].init)
			return;
		int bsize = btree->rbound/2, lqq = 1, rqq = bsize;
		if (r-l+1 < bsize)
			lqq = (l-1) % bsize + 1, rqq = (r-1) % bsize + 1;
		if (rqq < lqq)
			rqq += bsize;
		tree[n] = btree->query(1, btree->lbound, btree->rbound, lqq, rqq);
	}

	Node query(int n, int l, int r, int lq, int rq) {
		if (r < lq || rq < l || rq < lq) {
			return Node();
		} else if (lq <= l && r <= rq) {
			if (!tree[n].init)
				updateBackup(n, l, r);
			return tree[n];
		} else {
			int m = l+(r-l)/2;
			if (tree[n].lazy != -1) {
				update(n*2, l, m, l, r, tree[n].lazy);
				update(n*2+1, m+1, r, l, r, tree[n].lazy);
			}
			return join(query(n*2, l, m, lq, rq), query(n*2+1, m+1, r, lq, rq));
		}
	}
};

int main() {
	int n, k, q;
	scanf("%d %d", &n, &k);
	SegTree btree(1, n*2), tree(1, n*k, &btree);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		btree.update(1, 1, 2*n, i, i, x);
		btree.update(1, 1, 2*n, i+n, i+n, x);
	}
	scanf("%d", &q);
	for (int opt, lq, rq, v; q--;) {
		scanf("%d %d %d", &opt, &lq, &rq);
		if (opt == 1) {
			scanf("%d", &v);
			tree.update(1, 1, n*k, lq, rq, v);
		} else {
			printf("%d\n", tree.query(1, 1, n*k, lq, rq).value);
		}
	}
}
