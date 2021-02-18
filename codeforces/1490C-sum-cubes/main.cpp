#include <iostream>
#include <unordered_set>
typedef long long LL;
bool solve() {
	LL x;
	std::cin >> x;
	std::unordered_set<LL> d;
	for (LL i = 1; i*i*i <= x; ++i) {
		d.insert(i*i*i);
		if (d.count(x-i*i*i))
			return true;
	}
	return false;
}
int main() {
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t)
		std::cout << (solve() ? "YES" : "NO") << '\n';
}
