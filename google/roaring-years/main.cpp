#include <iostream>
#include <string>
#include <vector>
typedef long long LL;
inline bool isRoaring(LL x) {
	std::string s = std::to_string(x);
	LL start, length = s.size();
	for (LL i = 0; i < length/2; ++i) {
		std::string ns = s.substr(0, i+1);
		LL num = std::stoll(ns);
		while (ns.size() < length) {
			++num;
			ns += std::to_string(num);
		}
		if (ns == s)
			return true;
	}
	return false;
}
inline LL solve(LL x) {
	for (LL g = x+1; true; ++g)
		if (isRoaring(g))
			return g;
}
int main() {
	LL T;
	std::cin >> T;
	for (LL t = 1, x; t <= T; ++t) {
		std::cin >> x;
		if (x > 1e6)
			break;
		std::cout << "Case #" << t << ": " << solve(x) << '\n';
	}
}
