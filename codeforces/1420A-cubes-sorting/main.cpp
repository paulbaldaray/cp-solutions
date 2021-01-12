#include <iostream>
#include <vector>
using namespace std;
int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; ++i)
			cin >> v[i];
		bool rev_sorted = true;
		for (int i = 1; rev_sorted && i < N; ++i)
			if (v[i-1] <= v[i])
				rev_sorted = false;
		cout << (rev_sorted ? "NO" : "YES") << '\n';
	}
}
