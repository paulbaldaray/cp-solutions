#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
struct Trie {
	struct Node {
		int word_id = 0, id, children[26];
		Node(int id) : id{id} {
			std::fill(children, children+26, 0);
		};
	};

	int queries = 0;
	std::vector<int> words = {0}; // 1-index 0 reserved for NOT_WORD
	std::vector<Node> nodes = {Node(0)}; // root node

	int addWord(const std::string &word, int k) {
		int u = 0;
		for (int i = 0; i < word.size(); ++i) {
			if (nodes[u].children[word[i]-'a'] == 0) {
				nodes.emplace_back(nodes.size());
				nodes[u].children[word[i]-'a'] = nodes.back().id;
			}
			u = nodes[u].children[word[i]-'a'];
		}
		if (nodes[u].word_id == 0) {
			nodes[u].word_id = words.size();
			words.push_back(word.size());
		}
		return nodes[u].word_id;
	}

	std::vector<int> buildFailure() {
		std::vector<int> failure(nodes.size(), 0);
		std::deque<int> q;
		for (int c = 0, child; c < 26; ++c)
			if ((child = nodes[0].children[c]) != 0) {
				failure[child] = 0;
				q.push_back(child);
			}
		while (!q.empty()) {
			int u = q.front();
			q.pop_front();
			for (int c = 0, child; c < 26; ++c)
				if ((child = nodes[u].children[c]) != 0) {
					int v = failure[u];
					while (v && nodes[v].children[c] == 0)
						v = failure[v];
					failure[child] = nodes[v].children[c];
					q.push_back(child);
				}
		}
		return failure;
	}

	std::vector<std::vector<int>> aho(const std::string &s) {
		std::vector<int> failure = buildFailure();
		std::vector<std::vector<int>> wlocations(words.size());
		int u = 0, f = 1, v;
		for (int idx = 0, child; idx <= s.size(); ++idx) {
			for (int v = u, w; !f && v; v = failure[v])
				if ((w = nodes[v].word_id))
					wlocations[w].push_back(idx-words[w]);

			if (idx == s.size())
				continue;

			if ((child = nodes[u].children[s[idx]-'a']))
				u = child, f = 0;
			else
				idx -= !!u, u = failure[u], f = 1;
		}
		return wlocations;
	}
};

int main() {
	int Q;
	std::string s, t;
	std::cin >> s >> Q;
	std::vector<std::pair<int, int>> queries;
	Trie aho;
	for (int q = 0, k; q < Q; ++q) {
		std::cin >> t >> k;
		queries.push_back({aho.addWord(t, k), k-1});
	}
	auto wlocations = aho.aho(s);
	for (auto wk : queries)
		if (wk.second < wlocations[wk.first].size())
			std::cout << wlocations[wk.first][wk.second]+1 << '\n';
		else
			std::cout << -1 << '\n';
}
