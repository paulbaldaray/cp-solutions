#include <vector>
#include <cstdio>
#include <algorithm>
int gcd(int a, int b) {
	if (a > b)
		return gcd(b, a);
	if (a == 0 || a == b)
		return b;
	return gcd(a, b % a);
}
void solve() {
	int N;
	std::scanf("%d", &N);
	std::vector<int> arr(N);
	for (auto &x : arr)
		std::scanf("%d", &x);
	int m = std::min_element(arr.begin(), arr.end()) - arr.begin();
	int ans[] = {arr[m]+1, arr[m]};
	while (gcd(arr[m], ans[0]) != 1)
		++ans[0];
	std::printf("%d\n", N-1);
	for (int i = 0; i < N; ++i)
		if (i != m)
			std::printf("%d %d %d %d\n", m+1, i+1, arr[m], ans[i%2==m%2]);
}
int main() {
	int T;
	std::scanf("%d", &T);
	while (T--)
		solve();
}
