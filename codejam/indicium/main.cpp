#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mtx;
vector<long long> rset, cset;
int N, K;

bool backtrack(int r, int c) {
  if (c == N) c = 0, ++r;
  if (r == N) {
    int sum = 0;
    for (int i = 0; i < N; ++i)
      sum += mtx[i][i];
    return sum == K;
  }
  for (int i = 1; i <= N; ++i) {
    /* if (!(rset[r] & 1 << i) && !(cset[c] & 1 << i)) { */
    /*   rset[r] |= 1 << i; */
    /*   cset[c] |= 1 << i; */

      mtx[r][c] = i;
      bool cols = true, rows = true;
      for(int x = r-1; x >= 0; --x) if (mtx[x][c] == i) rows = false;
      for(int x = c-1; x >= 0; --x) if (mtx[r][x] == i) cols = false;
      if (rows && cols && backtrack(r, c+1)) return true;

      /* rset[r] ^= 1 << i; */
      /* cset[c] ^= 1 << i; */
    /* } */
  }
  return false;
}

int main() {
  int TC;
  cin >> TC;
  for (int tc = 1; tc <= TC; ++tc) {
    cin >> N >> K;
    cout << "Case #" << tc << ": ";
    mtx.resize(N, vector<int>(N));
    rset.resize(N, 0), cset.resize(N, 0);
    bool found = backtrack(0, 0);
    if (found) {
      cout << "POSSIBLE\n";
      for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
          cout << (c ? " " : "") << mtx[r][c];
        }
        cout << '\n';
      }
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }
}
