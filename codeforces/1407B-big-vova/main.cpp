#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
int main() {
	int TC; cin >> TC;
	while (TC--) {
		int N; cin >> N;
		vector<int> v(N), ans;
		for (int i = 0; i < N; ++i)
			cin >> v[i];
		int G = 0;
		while (v.size()) {
			int maxg = 0, a = 0;
			for (int i = 0; i < v.size(); ++i) {
				int g = G ? gcd(G, v[i]) : v[i];
				if (g > maxg) {
					maxg = g;
					a = i;
				}
			}
			ans.push_back(v[a]);
			v.erase(v.begin()+a);
			G = maxg;
		}
		for (int i = 0; i < N; ++i)
			cout << ans[i] << (i+1 == N ? '\n' : ' ');
	}
}
