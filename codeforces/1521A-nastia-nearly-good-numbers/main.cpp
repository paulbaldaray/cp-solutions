#include <stdio.h>
void solve() {
	long long A, B, x, y, z;
	scanf("%lld %lld", &A, &B);
	if (B == 1)
		printf("NO\n");
	else
		printf("YES\n%lld %lld %lld\n", A, A*B, A*(B+1));
}

int main() {
	long long T;
	scanf("%lld", &T);
	while (T--)
		solve();
}
