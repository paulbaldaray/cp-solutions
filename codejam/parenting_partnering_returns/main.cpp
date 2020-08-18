#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define F first
#define S second
using namespace std;
int main() {
  int TC; cin >> TC;
  for (int tc = 1; tc <= TC; ++tc) {
    cout << "Case #" << tc << ": ";
    int N; cin >> N;
    vector<pair<pair<int, int>, int>> intervals(N);
    for (int i = 0; i < N; ++i) {
      cin >> intervals[i].F.F >> intervals[i].F.S;
      intervals[i].S = i;
    }
    sort(intervals.begin(), intervals.end());
    int cameron = -1, jamie = -1;
    string ans;
    ans.resize(N);
    for (auto se : intervals) {
      if (se.F.F >= cameron) {
        cameron = se.F.S;
        ans[se.S] = 'C';
      } else if (se.F.F >= jamie) {
        jamie = se.F.S;
        ans[se.S] = 'J';
      } else {
        ans = "IMPOSSIBLE";
        break;
      } 
    }
    cout << ans << '\n';
  }
}
