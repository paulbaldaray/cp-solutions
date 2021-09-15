#include <cstdio>
int main() {
	int t, n, k;
	while (t--) {
		scanf("%d %d", &n, &k);
		/* array of size n, k length bits */
		/* 000 001 */
		/* 010 011 */
		/* 100 101 */
 		/* 110 111 */
		/* there are  1 << k-1 of each number */
		/* XOR odd = 0 */
		/* AND all = 1 */
		/* for each bit: */
		/* 	odd && all = (k-1) */
		/* 	even && all = win */
		/* 	odd && some = lose */
		/* 	none = (k-1) */
		/* 	(None) + (odd & all) */
	}
}
