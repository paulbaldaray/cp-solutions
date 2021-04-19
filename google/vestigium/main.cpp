#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
  int TC;
  cin >> TC;
  for (int tc = 1; tc <= TC; ++tc) {
    int N;
    cin >> N;
    vector<vector<int>> mtx(N, vector<int>(N));
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
      cin >> mtx[i][j];
    cout << "Case #" << tc << ": ";
    int k = 0, r = 0, c = 0;
    for (int i = 0; i < N; ++i) k += mtx[i][i];
    for (int i = 0; i < N; ++i) {
      unordered_set<int> used;
      for (int j = 0; j < N; ++j) {
        if (used.count(mtx[i][j]))
          goto repeated;
        else
          used.insert(mtx[i][j]);
      }
      continue;
      repeated: ++r;
    }
    for (int i = 0; i < N; ++i) {
      unordered_set<int> used;
      for (int j = 0; j < N; ++j) {
        if (used.count(mtx[j][i]))
          goto repeated2;
        else
          used.insert(mtx[j][i]);
      }
      continue;
      repeated2: ++c;
    }
    cout << k << " " << r << " " << c << '\n';
  }
}
