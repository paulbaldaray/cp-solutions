#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int T, a, b, c;
	cin >> T;
	while (T--) {
		cin >> a >> b >> c;
		cout << max(max(a, b), c) << '\n';
	}
}
