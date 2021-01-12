#include <iostream>
#include <string>
#include <climits>
#include <cassert>
typedef unsigned long long ULL;
std::string zero = "What are you doing at the end of the world? Are you busy? Will you save us?",
	begin = "What are you doing while sending \"",
	middle = "\"? Are you busy? Will you send \"",
	end = "\"?";

ULL fsize[100];
void calc(ULL n) {
	fsize[0] = zero.size();
	for (int i = 1; i < 100; ++i) {
		if (fsize[i-1] > 1e18)
			fsize[i] = 1e18+10;
		else
			fsize[i] = 2 * fsize[i-1] + begin.size() + middle.size() + end.size();
	}
}

char solve(ULL n, ULL k) {
	if (n == 0)
		return k <= zero.size() ? zero[k-1] : '.';

	if (k <= begin.size())
		return begin[k-1];
	k -= begin.size();

	if (n >= 100 || k <= fsize[n-1])
		return solve(n-1, k);
	k -= fsize[n-1];

	if (k <= middle.size())
		return middle[k-1];
	k -= middle.size();

	if (n >= 100 || k <= fsize[n-1])
		return solve(n-1, k);
	k -= fsize[n-1];

	if (k <= end.size())
		return end[k-1];
	k -= end.size();

	return '.';
}

int main() {
	ULL Q, n, k;
	std::cin >> Q;
	calc(99);
	for (ULL q = 0; q < Q; ++q) {
		std::cin >> n >> k;
		std::cout << solve(n, k);
	}
	std::cout << '\n';
}
