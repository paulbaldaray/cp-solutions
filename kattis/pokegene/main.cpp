#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
struct Trie {
	struct Node {
		int word_id = 0, id, parent, depth, children[26];
		Node(int id, int parent, int depth)
				: id{id}, parent{parent}, depth{depth} {
			std::fill(children, children+26, -1);
		};
	};

	std::vector<int> word_rank = {0}; // 1-index 0 reserved for NOT_WORD
	std::vector<int> word_term = {0}; // 1-index 0 reserved for NOT_WORD
	std::vector<Node> nodes = {Node(0, -1, 0)}; // root node
	std::vector<std::vector<int>> dp;

	void addWord(const std::string &word) {
		int u = 0;
		for (int i = 0; i < word.size(); ++i) {
			if (nodes[u].children[word[i]-'a'] == -1) {
				nodes.emplace_back(nodes.size(), u, i+1);
				nodes[u].children[word[i]-'a'] = nodes.back().id;
			}
			u = nodes[u].children[word[i]-'a'];
		}
		nodes[u].word_id = word_rank.size();
		word_rank.push_back(0);
		word_term.push_back(u);
	}

	void genWordRank() {
		int rank = 0;
		std::vector<std::pair<int, int>> stack = {{0, 0}};
		while (!stack.empty()) {
			int u = stack.back().first, c = stack.back().second;
			stack.pop_back();
			if (nodes[u].word_id && !word_rank[nodes[u].word_id])
				word_rank[nodes[u].word_id] = ++rank;
			while (c < 26 && nodes[u].children[c] == -1)
				++c;
			if (c < 26) {
				stack.push_back({u, c+1});
				stack.push_back({nodes[u].children[c], 0});
			}
		}
	}

	void sort(std::vector<int> &word_ids) {
		std::sort(word_ids.begin(), word_ids.end(), [&](int id1, int id2) {
			return word_rank[id1] < word_rank[id2];
		});
	}

	void binary_lift() {
		int height = log2(nodes.size())+1;
		dp.assign(nodes.size(), std::vector<int>(height, -1));
		for (int u = 0; u < nodes.size(); ++u)
			dp[u][0] = nodes[u].parent;
		for (int i = 1; i < height; ++i)
			for (int u = 0; u < nodes.size(); ++u)
				if (dp[u][i-1] != -1)
					dp[u][i] = dp[dp[u][i-1]][i-1];
	}

	int lca(int wid1, int wid2) {
		int u = word_term[wid1], v = word_term[wid2];
		int height = log2(nodes.size())+1;
		if (nodes[u].depth < nodes[v].depth)
			std::swap(u, v);
		for (int i = height-1; i >= 0; --i)
			if (nodes[u].depth - (1 << i) >= nodes[v].depth)
				u = dp[u][i];
		if (u == v)
			return nodes[u].depth;
		for (int i = height-1; i >= 0; --i)
			if (dp[u][i] != dp[v][i])
				u = dp[u][i], v = dp[v][i];
		return nodes[dp[u][0]].depth;
	}
};

int main() {
	int N, Q, K, L;
	std::cin >> N >> Q;
	Trie pokedex;
	for (int i = 0; i < N; ++i) {
		std::string p;
		std::cin >> p;
		pokedex.addWord(p);
	}
	pokedex.binary_lift();
	pokedex.genWordRank();
	for (int q = 0; q < Q; ++q) {
		std::cin >> K >> L;
		std::vector<int> pokemon(K);
		for (int i = 0; i < K; ++i)
			std::cin >> pokemon[i];
		pokedex.sort(pokemon);
		int ans = 0;
		for (int l = 0, r = L-1; r < K; ++l, ++r) {
			int middle = pokedex.lca(pokemon[l], pokemon[r]),
					left = l ? pokedex.lca(pokemon[l-1], pokemon[l]) : 0,
					right = r+1 < K ? pokedex.lca(pokemon[r], pokemon[r+1]) : 0;
			ans += std::max(0, middle - std::max(left, right));
		}
		std::cout << ans << '\n';
	}
}
