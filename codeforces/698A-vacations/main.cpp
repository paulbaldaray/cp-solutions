#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
int main() {
	int n, inf = 1e9;
	std::cin >> n;
	int contest = 1e9, gym = 1e9, neither = 0;
	for (int i = 0; i < n; ++i) {
		int type, contest1 = contest, gym1 = gym, neither1 = neither;
		std::cin >> type;
		contest = 1e9, gym = 1e9, neither = std::min(std::min(contest1, gym1), neither1)+1;
		if (type & 1) // is contest
			contest = std::min(gym1, neither1);
		if (type & 2) // is gym
			gym = std::min(contest1, neither1);
	}
	std::cout << std::min(std::min(contest, gym), neither) << '\n';
}
