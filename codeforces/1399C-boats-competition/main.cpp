#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> people(N);
		int high = 0;
		for (int i = 0; i < N; ++i) {
			cin >> people[i];
			high = max(high, people[i]+people[i]);
		}
		unordered_map<int, int> weights;
		int mcount = 0;
		for (int i = 2; i <= high; ++i) {
			weights.clear();
			int count = 0;
			for (int x : people) {
				if (weights[i-x] > 0) {
					++count;
					--weights[i-x];
				}
				else
					++weights[x];
			}
			mcount = max(mcount, count);
		}
		cout << mcount << '\n';
	}
}
