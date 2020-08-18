#include <iostream>
#include <string>
using namespace std;
int main() {
	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		string s; cin >> s;
		int ans = 0, ct = 0;
		for (char c : s) {
			if (c == '1')
				ans -= ct ? 1 : 0, ct = K;
			else if (ct == 0)
				++ans, ct = K;
			else
				--ct;
		}
		cout << ans << endl;
	}
}
