#include <iostream>
#include <vector>
using namespace std;
int main() {
	int TC; cin >> TC;
	while (TC--) {
		int N; cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; ++i)
			cin >> v[i];
		for (int i = 0; i < N; ++i) {
			int j = i;
			while (j < N && v[j])
				++j;
			if ((i-j)%2)
				v[j-1] = 2;
			i = j;
		}
		int idx = 0;
		for (auto it=v.begin(); it != v.end();) {
			if (*it == 2)
				it = v.erase(it);
			else
				++it;
		}
		cout << v.size() << '\n';
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << (i+1 == v.size() ? '\n' : ' ');
	}
}
