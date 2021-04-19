#include <iostream>
#include <cmath>
#include <iomanip>
int main() {
	double a, b, c, d, p;
	std::cin >> a >> b >> c >> d;
	p = (a+b+c+d)/2;
	std::cout << std::fixed << std::setprecision(15);
	std::cout << std::sqrt((p-a)*(p-b)*(p-c)*(p-d)) << '\n';
}
