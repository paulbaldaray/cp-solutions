#include <iostream>
#include <array>
#include <vector>
#include <unordered_map>
#define RETURN(X) {ret = (X); break;}
std::unordered_map<char, std::array<int, 2>> delta = {
	{'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}
};
const int MAX_N = 2e3 + 5, MAX_M = 2e3 + 5;
int N, M, T;
char board[MAX_N][MAX_M];
int memo[MAX_N][MAX_M];
std::vector<std::array<int, 2>> path;

void solve() {
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			memo[i][j] = -1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
				std::cin >> board[i][j];
	int ar = 0, ac = 0;
	for (int R = 0; R < N; ++R)
		for (int C = 0; C < M; ++C) {
			int r = R, c = C, ret = 0;
			while (true) {
				if (r < 0 || c < 0 || r >= N || c >= M)
					RETURN(0);

				if (memo[r][c] == -2) {
					int i = path.size() - 1;
					while (path[i][0] != r || path[i][1] != c)
						--i;
					for (int j = i; j < path.size(); ++j)
						memo[path[j][0]][path[j][1]] = path.size()-i;
				}

				if (memo[r][c] != -1)
					RETURN(memo[r][c]);

				path.push_back({r, c});
				memo[r][c] = -2;
				char d = board[r][c];
				r += delta[d][0], c += delta[d][1];
			}
			while (!path.empty()) {
				auto [r, c] = path.back();
				if (memo[r][c] == -2)
					memo[r][c] = ret + 1;
				path.pop_back();
				ret = memo[r][c];
			}

			if (memo[R][C] > memo[ar][ac])
				ar = R, ac = C;
		}
	std::cout << ar+1 << " " << ac+1 << " " << memo[ar][ac] << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> T;
	while (T--)
		solve();
}
