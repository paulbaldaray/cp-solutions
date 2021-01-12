#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
struct Node {
	int val, removed = false;
	Node *adj[4] = {nullptr};
	bool check() const {
		long long count = 0, total = 0;
		for (Node *node : adj)
			if (node)
				total += node->val, ++count;
		return count && count*val < total;
	}
	void remove(unordered_set<Node*> &next) {
		for (int i = 0; i < 4; ++i)
			if (adj[i])
				next.insert(adj[i]), adj[i]->adj[i^1] = adj[i^1];
			removed = true;
	}
};
long long solve() {
	long long R, C, ans = 0, total = 0;
	cin >> R >> C;
	vector<vector<Node*>> graph(R, vector<Node*>(C, nullptr));
	unordered_set<Node*> to_remove;
	for (int r = 0; r < R; ++r)
		for (int c = 0; c < C; ++c) {
			Node *node = new Node();
			cin >> node->val;
			if (r)
				node->adj[2] = graph[r-1][c], graph[r-1][c]->adj[3] = node;
			if (c)
				node->adj[0] = graph[r][c-1], graph[r][c-1]->adj[1] = node;
			graph[r][c] = node;
			to_remove.insert(node);
			total += node->val;
		}
	while (!to_remove.empty()) {
		ans += total;
		unordered_set<Node*> to_delete, next;
		for (auto node : to_remove)
			if (node->check())
				to_delete.insert(node);
		for (auto node : to_delete)
			node->remove(next), total -= node->val;
		to_remove.clear();
		for (auto node : next)
			if (!node->removed)
				to_remove.insert(node);
	}
	for (int r = 0; r < R; ++r)
		for (int c = 0; c < C; ++c)
			if(graph[r][c])
				delete graph[r][c];
	return ans;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
		cout << "Case #" << t << ": " << solve() << '\n';
}
