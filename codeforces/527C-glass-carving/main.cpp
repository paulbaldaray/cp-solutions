#include <iostream>
#include <algorithm>
#include <unordered_map>
struct Node {
	int l, r, v;
	Node(int l = -1, int r = -1, int v = 0) :
		l{l}, r{r}, v{v} {}
};
typedef std::unordered_map<int, Node> SegTree;
Node join(Node n1, Node n2) {
	int points[4] = {n1.l, n1.r, n2.l, n2.r};
	Node n3(n1.l, n2.r, std::max(n1.v, n2.v));
	if (n1.r != -1 && n2.l != -1)
		n3.v = std::max(n3.v, n2.l - n1.r);
	for (int i = 0; i < 4 && n3.l == -1; ++i)
		n3.l = points[i];
	for (int i = 3; i >= 0 && n3.r == -1; --i)
		n3.r = points[i];
	return n3;
}
void update(SegTree &tree, int n, int l, int r, int i) {
	int m = l+(r-l)/2;
	if (i == l && i == r) {
		tree[n] = Node(i, i, 0);
	} else {
		if (i <= m)
			update(tree, n*2, l, m, i);
		else
			update(tree, n*2+1, m+1, r, i);
		tree[n] = join(tree[n*2], tree[n*2+1]);
	}
}
Node query(SegTree &tree, int n, int l, int r, int lq, int rq) {
	int m = l+(r-l)/2;
	if (r < lq || rq < l || rq < lq)
		return Node();
	else if (lq <= l && r <= rq)
		return tree[n];
	else
		return join(query(tree, n*2, l, m, lq, rq),
				query(tree, n*2+1, m+1, r, lq, rq));
}
int main() {
	int w, h, n;
	std::cin >> w >> h >> n;
	SegTree hlines, vlines;
	update(hlines, 1, 0, h, 0);
	update(hlines, 1, 0, h, h);
	update(vlines, 1, 0, w, 0);
	update(vlines, 1, 0, w, w);
	while (n--) {
		char c; int x;
		std::cin >> c >> x;
		if (c == 'H')
			update(hlines, 1, 0, h, x);
		else
			update(vlines, 1, 0, w, x);
		long long mh = query(hlines, 1, 0, h, 0, h).v,
				 mv = query(vlines, 1, 0, w, 0, w).v;
		std::cout << mh*mv << '\n';
	}
}
