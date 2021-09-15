#include <cstdio>
#include <algorithm>
int t, n;
int a[(int)2e5];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		double sum = 0;
		int smax = -2e9;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
			smax = std::max(smax, a[i]);
		}
		sum = (sum-smax)/(n-1);
		printf("%f\n", sum+smax);
	}
}
