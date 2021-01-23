#include <iostream>
int main() {
	int N;
	std::cin >> N;
	int arr1 = -1, arr2 = -1, arr0 = -1;
	int ans = 0, dp_one = 0, dp_two = 0, dp_one_delta = 0;
	for (int i = 1; i <= N; ++i) {
		std::cin >> arr0;
		int dp_zero = arr1 < arr0 ? dp_one +1 : 1;
		int dp_zero_delta = std::max(std::max(
				i > 2 && arr2 < arr0-1 ? dp_two+2 : 1, // skip in the middle
				arr1 < arr0 ? dp_one_delta+1 : 1), // carry from skip
				i > 1 ? 2 : 0 // make the one before one lower
				);
		ans = std::max(ans, std::max(std::max(dp_zero, dp_zero_delta), dp_one + 1 /* end here */));
		arr2 = arr1, arr1 = arr0;
		dp_two = dp_one, dp_one = dp_zero, dp_one_delta = dp_zero_delta;
	}
	std::cout << ans << '\n';
}
