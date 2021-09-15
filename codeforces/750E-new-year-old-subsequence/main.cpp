#include <iostream>
#include <unordered_map>
struct Node {
	unsigned cost[5][5];
	Node(bool identity = true) {
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				cost[i][j] =  i == j && identity ? 0 : 1e9;
	}
};
std::unordered_map<int, Node> tree;
Node join(Node n1, Node n2) {
	Node n3(false);
	for (int i = 0; i < 5; ++i)
		for (int j = i; j < 5; ++j)
			for (int k = i; k <= j; ++k)
				n3.cost[i][j] = std::min(n3.cost[i][j], n1.cost[i][k] + n2.cost[k][j]);
	return n3;
}
Node query(int n, int l, int r, int lq, int rq) {
	int m = l+(r-l)/2;
	if (r < lq || rq < l || rq < lq)
		return Node();
	else if (lq <= l && r <= rq)
		return tree[n];
	return join(query(n*2, l, m, lq, rq), query(n*2+1, m+1, r, lq, rq));
}
void update(int n, int l, int r, int i, char c) {
	int m = l+(r-l)/2;
	if (i == l && l == r) {
		int state = std::string("2017").find(c);
		if (state != std::string::npos) {
			tree[n].cost[state][state] = 1;
			tree[n].cost[state][state+1] = 0;
		} else if (c == '6')
			tree[n].cost[3][3] = tree[n].cost[4][4] = 1;
	} else {
		if (i <= m)
			update(n*2, l, m, i, c);
		else
			update(n*2+1, m+1, r, i, c);
		tree[n] = join(tree[n*2], tree[n*2+1]);
	}
}
int main() {
	int n, q;
	std::string s;
	std::cin >> n >> q >> s;
	for (int i = 0; i < n; ++i)
		update(1, 1, s.size(), i+1, s[i]);
	for (int i = 0, lq, rq, ans; i < q; ++i) {
		std::cin >> lq >> rq;
		ans = query(1, 1, s.size(), lq, rq).cost[0][4];
		std::cout << (ans == 1e9 ? -1 : ans) << std::endl;
	}
}
