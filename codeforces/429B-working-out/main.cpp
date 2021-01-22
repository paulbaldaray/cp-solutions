#include <iostream>
#include <vector>
typedef std::vector<int> vi;
int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<vi> grid, uldp, urdp, dldp, drdp(n+2, vi(m+2));
	grid = uldp = urdp = dldp = drdp;
	for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				std::cin >> grid[i][j];
	for (int i = n; i >= 1; --i)
		for (int j = m; j >= 1; --j)
			drdp[i][j] = std::max(drdp[i+1][j], drdp[i][j+1])+grid[i][j];
	for (int i = n; i >= 1; --i)
		for (int j = 1; j <= m; ++j)
			dldp[i][j] = std::max(dldp[i+1][j], dldp[i][j-1])+grid[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			uldp[i][j] = std::max(uldp[i-1][j], uldp[i][j-1])+grid[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= 1; --j)
			urdp[i][j] = std::max(urdp[i-1][j], urdp[i][j+1])+grid[i][j];
	int ans = 0;
	for (int i = 2; i < n; ++i)
		for (int j = 2; j < m; ++j) {
			ans = std::max(ans, std::max(uldp[i][j-1]+urdp[i-1][j]+drdp[i][j+1]+dldp[i+1][j],
					uldp[i-1][j]+urdp[i][j+1]+drdp[i+1][j]+dldp[i][j-1]));
		}
	std::cout << ans << '\n';
}
