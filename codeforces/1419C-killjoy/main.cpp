#include <iostream>
#include <vector>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		int N, X; cin >> N >> X;
		vector<int> v(N);
		for (int i = 0; i < N; ++i)
			cin >> v[i];
		bool equals = true, contains = false;
		int difference = 0;
		for (int x : v) {
			equals &= X == x;
			contains |= X == x;
			difference += X - x;
		}
		if (equals)
			cout << 0;
		else if (contains || !difference)
			cout << 1;
		else
			cout << 2;
		cout << '\n';
	}
}
