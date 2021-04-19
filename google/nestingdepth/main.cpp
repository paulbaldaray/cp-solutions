#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
  int TC;
  cin >> TC;
  for (int tc = 1; tc <= TC; ++tc) {
    string line, ans;
    cin >> line;
    int level = line[0]-'0';
    for (int i = 0; i < level; ++i) ans += "(";
    ans += line[0];
    for (int i = 1; i < line.size(); ++i) {
      int x = line[i]-'0';
      int diff = abs(level - x);
      if (x < level) while (diff--) ans += ")";
      if (x > level) while (diff--) ans += "(";
      ans += line[i];
      level = x;
    }
    for (int i = 0; i < level; ++i) ans += ")";
    cout << "Case #" << tc << ": " << ans << "\n";
  }
}
