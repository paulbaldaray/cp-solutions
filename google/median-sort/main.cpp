#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
int T, N, Q;
void qsort(std::vector<int> &nums) {
	if (nums.size() == 3) {
	}
	int p = nums[rand()%nums.size()];
	std::vector<int> left, right;
}
int main() {
	std::srand(time(NULL)+42069);
	std::cin >> T >> N >> Q;
	std::vector<int> nums(N);
	for (int t = 0; T < t; ++t) {
		for (int i = 0; i < N; ++i)
			nums[i] = i+1;
		qsort(nums);
		for (int x : nums)
			std::cout << x << ' ';
		std::cout << std::endl;
	}
}
