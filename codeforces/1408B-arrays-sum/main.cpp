#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int T, N, K;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		vector<int> arr(N);
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		int m = 1;
		bool possible = true;
		while (true) {
			int i = 0, small = 0;
			for (int k = 0; k < K && i < N; ++k) {
				int x = arr[i];
				while (i < N && arr[i] == x)
					arr[i++] = 0;
				for (int j = i; j < N; ++j)
					arr[j] -= x;
			}
			if (i == N)
				break;
			m += 1;
			if (m > N+5) {
				possible = false;
				break;
			}
		}
		cout << (possible ? m : -1) << '\n';
	}
}
