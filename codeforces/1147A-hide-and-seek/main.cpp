#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
#define P(x) (range.count(x))
#define F first
#define S second
using namespace std;
int main() {
	int N, K; cin >> N >> K;
	unordered_map<int, pair<int, int>> range;
	for (int i = 0; i < K; ++i) {
		int x; cin >> x;
		if (!P(x))
			range[x] = {i, i};
		else {
			range[x].F = min(range[x].F, i);
			range[x].S = max(range[x].S, i);
		}
	}
	int ct = 0;
	for (int i = 1; i <= N; ++i) {
		if (!P(i))
			++ct;
		for (int j = i-1; j <= i+1; j+=2)
			if (j && j != N + 1 && (!P(i) || !P(j) || range[j].S < range[i].F))
				++ct;
	}
	cout << ct << '\n';
}
