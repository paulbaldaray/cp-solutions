#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string s; cin >> s;
	vector<int> counts(s.size());
	for (int i = 1; i < s.size(); ++i)
		counts[i] = counts[i-1] + (s[i-1] == s[i]);
	int M; cin >> M;
	while (M--) {
		int l, r; cin >> l >> r;
		cout << counts[r-1] - counts[l-1] << '\n';
	}
}
