#include <iostream>
#include <vector>
using namespace std;
int solve() {
	int n;
	cin >> n;
	vector<int> weights(n);
	for (int i = 0; i < n; ++i)
		cin >> weights[i];
	int ones = 0, twos = 0;
	for (int w : weights)
		++(w == 1 ? ones : twos);
	return !(ones % 2) && (twos % 2 == 0 || ones >= 2);
}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
		cout << (solve() ? "YES" : "NO") << '\n';
}
