#include <stdio.h>
inline long long gcd(long long a, long long b) {
	while (b > 0)
		a%=b,a^=b,b^=a,a^=b;
	return a;
}
int main() {
	long long n, m, a, g=0;
	scanf("%lld%lld\n%lld", &n, &m, &a);
	for (long long i = 1, t1=a, t2; i < n; ++i, t1=t2) {
		scanf("%lld", &t2);
		g = gcd(g, ((t2-t1)*((((t2-t1)>0)<<1)-1)));
	}
	for (long long i = 0, b; i < m; ++i) {
		scanf("%lld", &b);
		printf("%lld ", gcd(a+b, g));
	}
	printf("\n");
}
