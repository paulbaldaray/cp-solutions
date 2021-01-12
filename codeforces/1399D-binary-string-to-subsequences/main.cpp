#include <bits/stdc++.h>
using namespace std;
int main() {
	int T, N;
	string s;
	cin >> T;
	while (T--) {
		cin >> N >> s;
		int count = 1;
		unordered_set<int> arr[2];
		vector<int> ans;
		ans.push_back(count);
		arr[s[0]-'0'].insert(count);
		for (int i = 1; i < N; ++i) {
			int x = (s[i]-'0')^1;
			if (arr[x].empty())
				arr[x].insert(++count);
			int type = *(arr[x].begin());
			arr[x].erase(type);
			arr[x^1].insert(type);
			ans.push_back(type);
		}
		cout << count << '\n';
		for (int i : ans)
			cout << i << " ";
		cout << '\n';
	}
}
