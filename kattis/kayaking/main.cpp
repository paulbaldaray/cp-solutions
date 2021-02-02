#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#define F first
#define S second
typedef long long LL;
int main() {
	LL B, N, E, BV, NV, EV;
	std::cin >> B >> N >> E >> BV >> NV >> EV;
	LL M = (B+N+E)/2;
	std::vector<LL> kayaks(M);
	for (LL i = 0; i < M; ++i)
		std::cin >> kayaks[i];
	std::sort(kayaks.begin(), kayaks.end(), std::greater<LL>{});
	std::vector<std::pair<LL, LL>> choices{
		{BV+BV, 1|1}, {BV+NV, 1|2}, {BV+EV, 1|4},
		{NV+NV, 2|2}, {NV+EV, 2|4}, {EV+EV, 4|4},
	};
	std::sort(choices.begin(), choices.end());
	std::function<bool (LL)> predicate = [&](LL minimum) {
		LL b = B, n = N, e = E;
		for (LL k : kayaks) {
			for (auto sc : choices) {
				b -= !!(sc.S&1) + (sc.S==1), n -= !!(sc.S&2) + (sc.S==2), e -= !!(sc.S&4) + (sc.S==4);
				if (k * sc.F >= minimum && b >= 0 && n >= 0 && e >= 0)
					goto skip_false;
				b += !!(sc.S&1) + (sc.S==1), n += !!(sc.S&2) + (sc.S==2), e += !!(sc.S&4) + (sc.S==4);
			}
			return false;
			skip_false:;
		}
		return true;
	};
	LL l = 0, r = 1e18;
	while (r - l > 1) {
		LL m = l+(r-l)/2;
		if (predicate(m))
			l = m;
		else
			r = m;
	}
	std::cout << l << '\n';
}
