#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long LL;
using namespace std;
string solve() {
	LL n;
	cin >> n;
	vector<LL> points(n);
	for (int i = 0; i < n; ++i)
		cin >> points[i];
	sort(points.begin(), points.end());
	LL alice = 0, bob = 0, turn = 0;
	while (!points.empty()) {
		LL x = points.back();
		points.pop_back();
		if (turn == 0 && x % 2 == 0)
			alice += x;
		if (turn == 1 && x % 2 == 1)
			bob += x;
		turn ^= 1;
	}
	if (alice > bob)
		return "Alice";
	else if (bob > alice)
		return "Bob";
	else
		return "Tie";
}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
		cout << solve() << '\n';
}
