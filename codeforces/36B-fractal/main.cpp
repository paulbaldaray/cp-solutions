#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<string> ans, orig(n);
	for (int i = 0; i < n; ++i)
		cin >> orig[i];
	ans = orig;
	for (int i = 1; i < k; ++i) {
		vector<string> arr = ans;
		int nx = arr.size();
		ans.assign(nx*n, string(nx*n, '*'));
		for (int r = 0; r < nx; ++r)
			for (int c = 0; c < nx; ++c)
				for (int rx = 0; rx < n; ++rx)
					for (int cx = 0; cx < n; ++cx)
						if (arr[r][c] != '*')
							ans[r*n+rx][c*n+cx] = orig[rx][cx];
	}
	for (string &s : ans)
		cout << s << '\n';
}
