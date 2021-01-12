#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long LL;
void print(vector<LL> &v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << (i+1 < v.size() ? ' ' : '\n');
}
int main() {
	LL TC, N, T;
	cin >> TC;
	while (TC--) {
		cin >> N >> T;
		vector<LL> colors;
		unordered_map<LL, LL> c, d;
		while (N--) {
			LL x;
			cin >> x;
			LL paint = c[T-x] <= d[T-x] ? 0 : 1;
			unordered_map<LL, LL> &m = c[T-x] <= d[T-x] ? c : d;
			colors.push_back(paint);
			++m[x];
		}
		print(colors);
	}
}
