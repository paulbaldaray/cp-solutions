#include <iostream>
#define MOD(X) ((X)%(int)(1e9+7))
int main() {
	int N, K, ans = 0;
	std::cin >> N >> K;
	for (int k = K, sign = 1; k >= 2; --k, sign *= -1)
		ans = MOD(ans + MOD());
}
