#include <iostream>
int main() {
	int D, R, T;
	std::cin >> D >> R >> T;
	int rc = 0, tc = 0, rage = 4, tage = 3;
	while (rage < tage+D)
		rc += rage++;
	while (tc+rc < R+T)
		rc += rage++, tc += tage++;
	std::cout << R-rc << '\n';
}
