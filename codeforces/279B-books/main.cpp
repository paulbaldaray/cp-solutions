#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, T; cin >> N >> T;
	vector<int> v;
	int ans = 0, l = 0, t = 0;
	for (int r = 0; r < N; ++r) {
		int x; cin >> x;
		v.push_back(x);
		t += x;
		while (l < v.size() && t > T)
			t -= v[l++];
		ans = max(ans, r-l+1);
	}
	cout << ans << '\n';
}
