#include <iostream>
#include <vector>
#include <cmath>
long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main() {
	long long N, M;
	std::cin >> N >> M;
	std::vector<long long> a(N), b(M);
	for (long long i = 0; i < N; ++i)
		std::cin >> a[i];
	for (long long i = 0; i < M; ++i)
		std::cin >> b[i];
	long long gcd_a = 0;
	for (long long i = 1; i < N; ++i)
		gcd_a = gcd(std::abs(a[i]-a[i-1]), gcd_a);
	for (long long i = 0; i < M; ++i)
		std::cout << (N == 1 ? a[0] + b[i] : gcd(a[0]+b[i], gcd_a)) << ' ';
	std::cout << '\n';
}
