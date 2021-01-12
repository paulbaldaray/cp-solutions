#include <iostream>
using namespace std;
inline long long asum(unsigned long long a, unsigned long long d, unsigned long long n) {
	return n*(2LL*a + (n-1LL)*d)/2LL;
}
int main() {
	long long n;
	cin >> n;
	long long odds = n/2LL + n%2LL, evens = n/2LL;
	cout << asum(2LL, 2LL, evens) - asum(1LL, 2LL, odds) << '\n';
}
