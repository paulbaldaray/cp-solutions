#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <functional>
typedef std::pair<int, int> Tile;
typedef std::set<Tile> Omino;
typedef std::vector<bool> Row;
typedef std::vector<Row> Grid;
#define F first
#define S second
int R, C, X;

Omino invert(const Omino &o) {
	Omino inv;
	for (auto &t : o)
		inv.insert({t.S, t.F});
	return inv;
}

std::set<Omino> generateOminos() {
	std::set<Omino> ominos;
	Omino omino;
	std::function<void (int, int)> dfs = [&](int r, int c) {
		if (omino.size() == X)
			ominos.insert(omino);
		if (omino.size() == X || omino.count({r, c}))
			return;
		omino.insert({r, c});
		dfs(r+1, c), dfs(r, c+1);
		omino.erase({r, c});
	};
	dfs(0, 0);
	return ominos;
}

int ffdfs(Grid &g, int r, int c) {
	if (r < 0 || c < 0 || r == R || c == C || g[r][c])
		return 0;
	g[r][c] = true;
	int tiles = 1;
	for (Tile t : {Tile{0, 1}, {1, 0}, {0, -1}, {-1, 0}})
		tiles += ffdfs(g, t.F+r, t.S+c);
	return tiles;
}

std::vector<int> floodFill(Grid &g) {
	std::vector<int> comps;
	for (int r = 0; r < g.size(); ++r)
		for (int c = 0, sz; c < g[0].size(); ++c)
			if ((sz = ffdfs(g, r, c)))
				comps.push_back(sz);
	return comps;
}

bool possible(const Omino &o) {
	for (int sr = 0; sr < R; ++sr)
		for (int sc = 0; sc < C; ++sc) {
			Grid g(R, Row(C));
			for (auto &t : o) {
				int r = t.F + sr, c = t.S + sc;
				if (r >= R || c >= C)
					goto doesnt_work;
				g[r][c] = true;
			}
			for (auto sz : floodFill(g))
				if (sz % o.size() != 0)
					goto doesnt_work;
			return true;
doesnt_work:;
		}
	return false;
}

bool solve() {
	std::cin >> X >> R >> C;
	if (X >= 7)
		return false;
	for (auto &o : generateOminos())
		if (!possible(o) && !possible(invert(o)))
			return false;
	return true;
}

int main() {
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t)
		std::cout << "Case #" << t << ": " << (solve()?"GABRIEL":"RICHARD") << '\n';
}
