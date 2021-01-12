#include <iostream>
#include <string>
using namespace std;
int main() {
	int T, N;
	cin >> T;
	while (T--) {
		string s;
		cin >> N >> s;
		int raze_odd = 0, raze_even = 0;
		int breach_even = 0, breach_odd = 0;
		int turn = 1;
		for (char c : s) {
			bool odd = (c - '0') % 2;
			if (turn)
				raze_odd += odd, raze_even += !odd;
			else
				breach_odd += odd, breach_even += !odd;
			turn ^= 1;
		}
		turn = 1;
		for (int i = 0; i < N-1; ++i) {
			if (turn && raze_even)
				raze_even -= 1;
			else if (turn)
				raze_odd -= 1;
			else if (breach_odd)
				breach_odd -= 1;
			else
				breach_even -= 1;
			turn ^= 1;
		}
		int ans = raze_odd || breach_odd ? 1 : 2;
		cout << ans << '\n';
	}
}
