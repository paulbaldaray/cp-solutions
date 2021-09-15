#include <cstdio>
#include <vector>
#include <algorithm>
int main() {
	int n, m, ans = 1e9;
	scanf("%d %d", &n, &m);
	std::vector<int> vlines(n), hlines;
	for (int i = 0; i < n; ++i)
		scanf("%d", &vlines[i]);
	for (int i = 0, l, r, y; i < m; ++i) {
		scanf("%d %d %d", &l, &r, &y);
		if (l == 1)
			hlines.push_back(-r);
	}
	sort(vlines.begin(), vlines.end());
	sort(hlines.begin(), hlines.end());
	vlines.push_back(1e9);
	for (int i = 0; i < vlines.size(); ++i) {
		while (!hlines.empty() && -hlines.back() < vlines[i])
			hlines.pop_back();
		ans = std::min(ans, (int)hlines.size() + i);
	}
	printf("%d\n", ans);
}
