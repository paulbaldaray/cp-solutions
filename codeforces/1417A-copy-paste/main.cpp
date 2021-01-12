#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
	LL T, N, K;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		vector<LL> arr(N);
		for (LL i = 0; i < N; ++i)
			cin >> arr[i];
		sort(arr.begin(), arr.end());
		LL ans = 0;
		for (LL i = N-1; i > 0; --i)
			ans += (K - arr[i]) / arr[0];
		cout << ans << '\n';
	}
}
