#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
int main() {
	int t, n, k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		std::vector<int> v;
		std::unordered_map<int, std::unordered_set<int>> elem;
		std::unordered_map<int, std::vector<int>> arr;
		for (int i = 0, x; i < n; ++i) {
			scanf("%d", &x);
			if (!elem.count(x))
				v.push_back(x);
			elem[x].insert(i);
			arr[x].push_back(i);
		}
		std::sort(v.begin(), v.end());
		int ans = 1;
		for (int i = 1; i < v.size(); ++i)
			if (!elem[v[i]].count(arr[v[i-1]].back()+1) && !elem[v[i-1]].count(arr[v[i]][0]-1))
				ans += 1;
		for (auto &kv : arr) {
			auto &a = kv.second;
			for (int i = 1; i < a.size(); ++i)
				if (a[i-1] != a[i]-1)
					ans += 1;
		}
		printf("%s\n", ans <= k ? "Yes" : "No");
	}
}
