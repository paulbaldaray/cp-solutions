#include <iostream>
#include <cmath>
#include <iomanip>
struct Point {
	double x, y;
};
Point p1, p2, p3;
double distance(Point p1, Point p2) {
	return std::sqrt(std::pow(p1.x - p2.x, 2)+std::pow(p1.y - p2.y, 2));
}
double centerValue(Point p) {
	return distance(p1, p) + distance(p2, p) + distance(p3, p);
}
int main() {
	std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
	Point ans = {0, 0};
	double jump = 1000;
	while (jump > (1/1e6)) {
		for (int dx = -1; dx <= 1; ++dx)
			for (int dy = -1; dy <= 1; ++dy) {
				Point p = {ans.x + jump*dx, ans.y + jump*dy};
				if (centerValue(p) < centerValue(ans)) {
					ans = p;
					goto skip;
			}
		}
		jump /= 2.0;
		skip:;
	}
	std::cout << std::setprecision(9) << std::fixed << ans.x << " " << ans.y << std::endl;
}
