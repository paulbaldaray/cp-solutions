#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
	LL T, N, M;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<vector<LL>> matrix(N, vector<LL>(M));
		for (LL i = 0; i < N; ++i)
			for (LL j = 0; j < M; ++j)
				cin >> matrix[i][j];
		LL ans = 0;
		set<pair<LL, LL>> vis;
		for (LL i = 0; i < N; ++i)
			for (LL j = 0; j < M; ++j) {
				if (vis.count({i, j}))
					continue;
				vector<LL> nums;
				if (!vis.count({i, j}))
					nums.push_back(matrix[i][j]*2);
				vis.insert({i, j});
				if (!vis.count({i, M-j-1}))
					nums.push_back(matrix[i][M-j-1]*2);
				vis.insert({i, M-j-1});
				if (!vis.count({N-i-1, j}))
					nums.push_back(matrix[N-i-1][j]*2);
				vis.insert({N-i-1, j});
				if (!vis.count({N-i-1, M-j-1}))
					nums.push_back(matrix[N-i-1][M-j-1]*2);
				vis.insert({N-i-1, M-j-1});
				sort(nums.begin(), nums.end());
				LL median;
				LL n = nums.size();
				if (n % 2)
					median = nums[n/2];
				else
					median = (nums[n/2-1] + nums[n/2]) / 2;
				LL diff = 0;
				for (LL x : nums)
					diff += abs(x - median);
				ans += diff / 2;
			}
		cout << ans << '\n';
	}
}
