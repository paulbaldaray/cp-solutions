#include <bits/stdc++.h>
using namespace std;
int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> v(N);
		int total = 0;
		for (int i = 0; i < N; ++i) {
			cin >> v[i];
			total += v[i];
		}
		int sum = 0, i;
		sort(v.begin(), v.end());
		vector<int> ans;
		for (i = 0; i < v.size() && sum+v[i] <= 0; ++i) {
				sum += v[i];
				ans.push_back(v[i]);
		}
		if (ans.size() != v.size())
			reverse(ans.begin(), ans.end());
		if (total == 0)
			cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			for (; i < v.size(); ++i)
				cout << v[i] << (i+1 == v.size() && ans.empty() ? "\n" : " ");
			for (int i = 0; i < ans.size(); ++i)
				cout << ans[i] << (i+1 == ans.size() ? "\n" : " ");
		}
	}
}
