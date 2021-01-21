#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define F first
#define S second
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
void solve() {
	int N;
	cin >> N;
	vector<piii> friends(N);
	for (int i = 0; i < N; ++i) {
		cin >> friends[i].F.F >> friends[i].F.S;
		if (friends[i].F.F > friends[i].F.S)
			swap(friends[i].F.F, friends[i].F.S);
		friends[i].S = i;
	}
	sort(friends.begin(), friends.end());
	multimap<int, int> to_do;
	vector<int> ans(N, -1);
	int i = N-1;
	while (i >= 0) {
		pii min_width = {INT_MAX, -1};
		vector<piii> current;
		do {
			current.push_back(friends[i--]);
			min_width = min(min_width, {current.back().F.S, current.back().S});
		} while (i >= 0 && friends[i].F.F == current.back().F.F);
		auto it = to_do.end();
		while ((it = to_do.upper_bound(min_width.F)) != to_do.end()) {
			ans[it->S] = min_width.S+1;
			to_do.erase(it);
		}
		for (piii x : current)
			to_do.insert({x.F.S, x.S});
	}
	for (int i = 0; i < N; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
		solve();
}
