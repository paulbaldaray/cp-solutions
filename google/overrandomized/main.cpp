#include <iostream>
#include <map>
using namespace std;
int main() {
  int TC; cin >> TC;
  for (int tc = 1; tc <= TC; ++tc) {
    int U; cin >> U;
    map<char, int> count;
    for (int i = 0; i < 1e4; ++i) {
      string Q, R; cin >> Q >> R;
      for (char c : R)
        if (!count.count(c))
          count[c] = 1;
      if (R.size() != 1)
        ++count[R[0]];
    }
    map<int, char> inv_count;
    for (auto kv : count)
      inv_count[kv.second] = kv.first;
    string ans;
    for (auto kv : inv_count)
      ans = kv.second + ans;
    cout << "Case #" << tc << ": " << ans[ans.size()-1] << ans.substr(0, ans.size()-1) << '\n';
  }
}
