#include <iostream>
#include <vector>
bool isSorted(std::vector<int> &a) {
	for (int i = 1; i < a.size(); ++i)
		if (a[i-1] > a[i])
			return false;
	return true;
}

int minCost(std::vector<int> a, bool z) {
	int ans = 0, n = a.size()/2;
	for (int i = 0; i < n; ++i) {
		if (z) {
			if (isSorted(a))
				return ans;
			for (int i = 0; i < n; ++i)
				std::swap(a[i], a[n+i]);
			++ans;
		}
		if (isSorted(a))
			return ans;
		for (int i = 1; i < 2*n; i += 2)
			std::swap(a[i-1], a[i]);
		++ans;
		if (!z) {
			if (isSorted(a))
				return ans;
			for (int i = 0; i < n; ++i)
				std::swap(a[i], a[n+i]);
			++ans;
		}
	}
	return isSorted(a) ? ans : 1e9;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(2*n);
	for (int i = 0; i < 2*n; ++i)
		std::cin >> a[i];
	int ans = std::min(minCost(a, false), minCost(a, true));
	std::cout << (ans != 1e9 ? ans : -1) << '\n';
}
