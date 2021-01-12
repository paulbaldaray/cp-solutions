#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
#define F first
#define S second
int delta[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
	int N, M, Q;
	cin >> N >> M;
	vector<vector<int>> matrix(N, vector<int>(M));
	for(int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			char c;
			cin >> c;
			matrix[i][j] = c-'0';
		}
	int count = 2;
	stack<pair<int,int>> st;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (matrix[i][j] > 1)
				continue;
			int val = matrix[i][j];
			st.push({i, j});
			while (!st.empty()) {
				int r = st.top().F, c = st.top().S;
				st.pop();
				if (r < 0 || c < 0 || r >= N || c >= M || matrix[r][c] != val)
					continue;
				matrix[r][c] += count;
				for (auto &d : delta)
					st.push({r+d[0], c+d[1]});
			}
			count += 2;
		}
	}
	cin >> Q;
	int a, b, c, d;
	while (Q--) {
		cin >> a >> b >> c >> d;
		if (matrix[a-1][b-1] != matrix[c-1][d-1])
			cout << "neither\n";
		else
			cout << (matrix[a-1][b-1]%2 ? "decimal" : "binary") << '\n';
	}
}
