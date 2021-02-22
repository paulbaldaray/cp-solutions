#include <iostream>
#include <string>
#include <algorithm>
bool dp[205][205][205] = {false};
int main() {
	int N;
	std::cin >> N;
	std::string s;
	std::cin >> s;
	int red = 0, green = 0, blue = 0;
	for (int i = 0; i < N; ++i)
		switch (s[i]) {
			case 'R': ++red; break;
			case 'G': ++green; break;
			case 'B': ++blue; break;
		}
	dp[red][green][blue] = true;
	for (int sz = N; sz >= 1; --sz)
		for (int r = 0; r <= sz; ++r)
			for (int g = 0; g+r <= sz; ++g) {
				int b = sz-r-g;
				if (dp[r][g][b]) {
					if (r >= 2)
						dp[r-1][g][b] = true;
					if (g >= 2)
						dp[r][g-1][b] = true;
					if (b >= 2)
						dp[r][g][b-1] = true;
					if (r && g)
						dp[r-1][g-1][b+1] = true;
					if (r && b)
						dp[r-1][g+1][b-1] = true;
					if (g && b)
						dp[r+1][g-1][b-1] = true;
				}
			}
	if (dp[0][0][1])
		std::cout << 'B';
	if (dp[0][1][0])
		std::cout << 'G';
	if (dp[1][0][0])
		std::cout << 'R';
	std::cout << '\n';
}
