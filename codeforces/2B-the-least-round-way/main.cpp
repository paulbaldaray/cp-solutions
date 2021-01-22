#include <iostream>
#include <vector>
struct TwoFive {
	int two, five, zero;
	TwoFive(int two, int five, int zero = false)
		: two{two}, five{five}, zero{zero} {}
	inline TwoFive operator+(const TwoFive &o) {
		return zero || o.zero ? TwoFive(1, 1, true) : TwoFive(two+o.two, five+o.five);
	}
	inline int zeroes() const {
		return std::min(two, five);
	}
};
inline bool lt(const TwoFive &a, const TwoFive &b, bool two) {
	return two ? a.two < b.two : a.five < b.five;
}
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<TwoFive> vf;
typedef std::vector<vf> vvf;
TwoFive factorize(int x) {
	if (x == 0)
		return TwoFive(1, 1, true);
	TwoFive tf(0, 0);
	while (x && x%5 == 0)
		x/=5, ++tf.five;
	while (x && x%2 == 0)
		x/=2, ++tf.two;
	return tf;
}
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	vvi matrix(n, vi(n));
	for (int i = 0, x; i < n; ++i)
		for (int j = 0; j < n; ++j)
			std::cin >> matrix[i][j];
	std::vector<vvf> dp(2, vvf(n, vf(n, TwoFive(1e9, 1e9))));
	std::vector<vvi> bptr(2, vvi(n, vi(n, false)));
	dp[0][n-1][n-1] = factorize(matrix[n-1][n-1]);
	dp[1][n-1][n-1] = factorize(matrix[n-1][n-1]);
	for (int i = n-1; i >= 0; --i)
		for (int j = n-1; j >= 0; --j)
			for (int k = 1; k >= 0; --k) {
			TwoFive tf = factorize(matrix[i][j]);
			if (i != n-1 && lt(dp[k][i+1][j]+tf, dp[k][i][j], k))
				dp[k][i][j] = dp[k][i+1][j]+tf, bptr[k][i][j] = true;
			if (j != n-1 && lt(dp[k][i][j+1]+tf, dp[k][i][j], k))
				dp[k][i][j] = dp[k][i][j+1]+tf, bptr[k][i][j] = false;
		}
	vvf *ans = &dp[1];
	vvi *ansp = &bptr[1];
	if(dp[0][0][0].zeroes() < dp[1][0][0].zeroes())
		ans = &dp[0], ansp = &bptr[0];
	std::cout << (*ans)[0][0].zeroes() << '\n';
	int i = 0, j = 0;
	while (!(i == n-1 && j == n-1)) {
		if ((*ansp)[i][j])
			std::cout << 'D', ++i;
		else
			std::cout << 'R', ++j;
	}
	std::cout << '\n';
}
