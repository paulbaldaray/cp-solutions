#include <iostream>
int main() {
	char x, y;
	int p1 = 0, p2 = 0, t = 0;
	while (std::cin >> x >> y) {
		if (x == y)
			++t;
		else if ((x == 'R' && y == 'S')
				|| (x == 'S' && y == 'P')
				|| (x == 'P' && y == 'R'))
			++p1;
		else
			++p2;
	}
	std::cout << p1 << ' ' << p2 << ' ' << t << '\n';
}
