#include <iostream>
#include <vector>
int main() {
	int N;
	std::cin >> N;
	std::vector<char> v(N);
	for (int i = 0; i < N; ++i)
		std::cin >> v[i];
	int ans = 0;
	for (int i = 1; i < N; ++i)
		ans += (v[i] == v[i-1]);
	std::cout << ans << '\n';
}
