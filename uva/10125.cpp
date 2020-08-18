#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while(cin >> n && n) {
    long x, ans = LONG_MIN;
    vector<long> arr;
    unordered_set<long> checker;
    while(n-- && cin >> x) {
      arr.push_back(x);
      checker.insert(x);
    }
    for(int a = arr.size()-1; a >= 0; --a)
      for(int b = a-1; b >= 0; --b)
        for(int c = b-1; c >= 0; --c)
        {
          long d = arr[a] + arr[b] + arr[c];
          if(checker.find(d) != checker.end() && arr[a] != d && arr[b] != d && arr[c] != d)
            ans = max(ans, d);
        }
    if(ans == LONG_MIN)
      cout << "no solution" << "\n";
    else
      cout << ans << "\n";
  }
}
