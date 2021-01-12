#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
	LL N, K;
	cin >> N >> K;
	vector<LL> players(N);
	for (LL i = 0; i < N; ++i)
		cin >> players[i];
	LL ans = 0, wins = 0;
	for (LL i = 1; i < N; ++i) {
		if (players[ans] < players[i])
			wins = 1, ans = i;
		else
			++wins;
		if (wins >= K)
			break;
	}
	if (wins >= K)
		cout << players[ans] << '\n';
	else
		cout << *max_element(players.begin(), players.end()) << '\n';
}
