#include <iostream>
#include <vector>
#include <algorithm>
typedef long long LL;
void solve() {
	LL N;
	std::cin >> N;
	std::vector<LL> arr(N+2);
	for (LL i = 0; i < N+2; ++i)
		std::cin >> arr[i];
	std::sort(arr.begin(), arr.end());
	LL total = 0;
	for (LL i = 0; i < N+1; ++i)
		total += arr[i];
	for (LL i = 0; i < N+1; ++i) {
		if (total-arr[i] == arr[i] || total-arr[i] == arr.back()) {
			for (LL j = 0; j < N+1; ++j)
				if (i != j)
					std::cout << arr[j] << ' ';
			std::cout << '\n';
			return;
		}
	}
	std::cout << "-1\n";
}
int main() {
	LL T;
	std::cin >> T;
	for (LL t = 0; t < T; ++t)
		solve();
}
