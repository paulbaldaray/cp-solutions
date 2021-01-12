#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; ++i)
			cin >> v[i];
		sort(v.begin(), v.end());
		bool can_find = true;
		for (int i = 1; i < N; ++i)
			if (v[i] > v[i-1]+1)
				can_find = false;
		cout << (can_find ? "YES" : "NO") << endl;
	}
}
