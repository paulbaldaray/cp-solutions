#include <iostream>
using namespace std;
typedef long long LL;
int main () {
	LL T; cin >> T;
	while (T--) {
		LL X; cin >> X;
		LL prev = 0, current = 1, count = 0;
		while (prev * 2 + current * current <= X) {
			prev = prev * 2 + current * current;
			X -= prev;
			current *= 2;
			++count;
		}
		cout << count << '\n';
	}
}
