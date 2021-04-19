#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
inline void prc(int r, int c) { cout << r << ' ' << c << '\n'; }
inline void down(int &r, int &c) {
  if (c != 1) ++c;
  ++r;
  prc(r, c);
}
inline void across(int &r, int &c, int &k) {
  if (c == 1) {
    for (++c; c <= r; ++c) prc(r,c);
    --c;
  } else {
    for (--c; c >= 1; --c) prc(r,c);
    ++c;
  }
  ++k;
}

int main() {
  int TC; cin >> TC;
  for (int tc = 1; tc <= TC; ++tc) {
    cout << "Case #" << tc << ":\n";
    int N; cin >> N;
    int B = min(N, 30);
    N -= 30;
    int r = 0, c = 1, k = 0;
    for (int i = 0; i < B; ++i) {
      down(r, c);
      if (N > 0 && N & 1 << i) across(r, c, k);
    }
    while(k--) down(r, c);
  }
}
