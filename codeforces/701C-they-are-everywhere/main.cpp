#include <iostream>
#include <string>
using namespace std;
int main() {
	int N; cin >> N;
	string s; cin >> s;
	int count[256] = {0};
	int ct = 0;
	for (char c : s)
		ct += !(count[c]++);
	fill(count, count + 256, 0);
	int l = 0, ans = s.size(), cr = 0;
	for (int r = 0; r < s.size(); ++r) {
		cr += !(count[s[r]]++);
		while (cr == ct) {
			ans = min(ans, r - l + 1);
			cr -= !(--count[s[l++]]);
		}
	}
	cout << ans << '\n';
}
