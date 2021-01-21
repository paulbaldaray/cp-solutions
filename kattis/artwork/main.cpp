#include <iostream>
#include <unordered_map>
#include <vector>
#define F first
#define S second
typedef std::pair<int,int> pii;
typedef std::pair<pii, int> piii;
int N, M, Q;
std::vector<int> parent;
std::vector<std::vector<int>> matrix;
std::vector<std::pair<pii, pii>> strokes;

int find(int u) {
	return u == parent[u] ? u : parent[u] = find(parent[u]);
}

int uni(int u, int v) {
	int pu = find(u), pv = find(v);
	if (pu == pv)
		return 0;
	parent[pu] = pv;
	return 1;
}

pii delta[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void floodfill(int r, int c, int color) {
	if (r < 0 || r >= M || c < 0 || c >= N || matrix[r][c] != 0)
		return;
	matrix[r][c] = color;
	for (pii rcd : delta)
		floodfill(r+rcd.F, c+rcd.S, color);
}

int main() {
	std::cin >> N >> M >> Q;
	matrix.resize(M, std::vector<int>(N, 0));
	for (int q = 0; q < Q; ++q) {
 		int c1, r1, c2, r2;
		std::cin >> c1 >> r1 >> c2 >> r2;
		--c1, --r1, --c2, --r2;
		strokes.push_back({pii{r1, c1}, pii{r2, c2}});
		if (r1 == r2)
			for (int c = c1; c <= c2; ++c)
				matrix[r1][c] -= 1;
		else
			for (int r = r1; r <= r2; ++r)
				matrix[r][c1] -= 1;
	}
	parent.resize(1);
	int color = 0;
	for (int r = 0; r < M; ++r)
		for (int c = 0; c < N; ++c)
			if (matrix[r][c] == 0) {
				++color;
				parent.push_back(color);
				floodfill(r, c, color);
			}

	int current = color;
	std::vector<int> vans;
	vans.push_back(current);
	while (strokes.size() > 1) {
		std::pair<pii, pii> s = strokes.back();
		strokes.pop_back();
 		int r1 = s.F.F, c1 = s.F.S, r2 = s.S.F, c2 = s.S.S;
		bool continuing = false;
		std::vector<piii> squares;
		std::unordered_map<int, int> unions;
		int lo = r1 == r2 ? c1 : r1, hi = r1 == r2 ? c2 : r2;
		for (int x = lo; x <= hi; ++x) {
			pii rc = r1 == r2 ? pii{r1, x} : pii{x, c1};
			if (++matrix[rc.F][rc.S] == 0) {
				if (continuing == false) {
					++color;
					parent.push_back(color);
				}
				matrix[rc.F][rc.S] = color;
				squares.push_back({{rc.F, rc.S}, color});
				continuing = true;
			} else {
				continuing = false;
			}
		}
		for (piii sq : squares) {
			int r = sq.F.F, c = sq.F.S, col = sq.S;
			int up = r+1 < M ? matrix[r+1][c] : -1;
			int down = r > 0 ? matrix[r-1][c] : -1;
			int right = c+1 < N ? matrix[r][c+1] : -1;
			int left = c > 0 ? matrix[r][c-1] : -1;
			unions[col]; // set it to zero
			if (up > 0)
				unions[col] += uni(up, col);
			if (down > 0)
				unions[col] += uni(down, col);
			if (right > 0)
				unions[col] += uni(right, col);
			if (left > 0)
				unions[col] += uni(left, col);
		}
		for (auto kv : unions)
			current -= kv.S-1;
		vans.push_back(current);
	}

	while(!vans.empty()) {
		std::cout << vans.back() << '\n';
		vans.pop_back();
	}
}
