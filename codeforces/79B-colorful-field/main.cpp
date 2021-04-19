#include <iostream>
#include <vector>
#include <algorithm>
#define IDX(R, C) ((R-1)*M + (C-1))
const char *plants[] = {"Carrots", "Kiwis", "Grapes"};
int main() {
	int N, M, K, T;
	std::cin >> N >> M >> K >> T;
	std::vector<int> waste;
	for (int i = 0, r, c; i < K; ++i) {
		std::cin >> r >> c;
		waste.push_back(IDX(r, c));
	}
	std::sort(waste.begin(), waste.end());
	for (int i = 0, r, c; i < T; ++i) {
		std::cin >> r >> c;
		int idx = IDX(r, c);
		auto it = std::lower_bound(waste.begin(), waste.end(), idx);
		if (it != waste.end() && *it == idx)
			std::cout << "Waste\n";
		else
			std::cout << plants[(idx-(it-waste.begin()))%3] << "\n";
	}
}
