#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	int T, N, K;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		string s;
		cin >> s;
		int i = 0, ws = 0, wstreaks = 0;
		vector<int> scount(s.size());
		while (i < s.size() && s[i] == 'L')
			++i;
		while (i < s.size()) {
			while (i < s.size() && s[i] == 'W')
				++i, ++ws;
			++wstreaks;
			int lstreak = 0;
			while (i < s.size() && s[i] == 'L')
				++i, ++lstreak;
			if (i != s.size())
				++scount[lstreak];
		}
		for (int i = 1; i < scount.size(); ++i) {
			int count = min(scount[i], K/i);
			K -= count*i;
			wstreaks -= count;
			ws += count*i;
		}
		ws += min(K, (int)s.size()-ws);
		if (wstreaks == 0 && ws)
			wstreaks = 1;
		int score = 2*ws - wstreaks;
		cout << score << '\n';
	}
}
