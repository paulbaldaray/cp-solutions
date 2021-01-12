#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int,int> ii;
int main() {
	int N, M;
	cin >> N >> M;
	vector<ii> robbers(N);
	vector<ii> searchlights;
	for (int i = 0; i < N; ++i)
		cin >> robbers[i].F >> robbers[i].S;
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y;
		for (auto &xy : robbers)
			if (x - xy.F >= 0 && y-xy.S >= 0)
				searchlights.push_back({x-xy.F+1, y-xy.S+1});
	}
	sort(searchlights.begin(), searchlights.end(), greater<ii>());
	int ans = INT_MAX, height = 0;
	for (auto &xy : searchlights) {
		ans = min(ans, xy.F + height);
		height = max(height, xy.S);
	}
	ans = min(ans, height);
	cout << ans << '\n';
}
