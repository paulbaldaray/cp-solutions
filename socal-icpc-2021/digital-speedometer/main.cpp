#include <iostream>
#include <vector>
typedef long long LL;
int main() {
	double tf, tr;
	std::cin >> tf >> tr;
	std::vector<double> speeds;
	for (double s; std::cin >> s;)
		speeds.push_back(s);
	for (LL k = 0; k < speeds.size(); ++k) {
		double s = speeds[k];
		LL i = s, j = s+1;
		if (0 < s && s < 1)
			std::cout << 1 << '\n';
		else if (i <= s && s <= i+tf)
			std::cout << i << '\n';
		else if (i+tr <= s && s <= j)
			std::cout << j << '\n';
		else if (i+tf <= s && s <= i+tr) {
			LL p = k-1;
			while (p > 0 && i+tf <= speeds[p] && speeds[p] <= i+tr)
				--p;
			double val = speeds[p];
			if (val < i + tr)
				std::cout << i << '\n';
			else
				std::cout << j << '\n';
		}
	}
}
