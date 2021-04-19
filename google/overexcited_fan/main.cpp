#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
int main() {
  int TC; cin >> TC;
  for (int tc=1; tc <= TC; ++tc) {
    int X, Y;
    cin >> X >> Y;
    string path;
    cin >> path;
    cout << "Case #" << tc << ": ";
    int small = abs(X) + abs(Y) == 0 ? 0 : INT_MAX;
    int i = 1;
    for (char c : path) {
      switch (c) {
        case 'N':
          ++Y;
          break;
        case 'E':
          ++X;
          break;
        case 'S':
          --Y;
          break;
        case 'W':
          --X;
          break;
      }
      int dist = abs(X) + abs(Y);
      if (i >= dist) small = min(small, i);
      ++i;
    }
    if (small <= path.size()) cout << small << "\n";
    else cout << "IMPOSSIBLE\n";
  }
}
