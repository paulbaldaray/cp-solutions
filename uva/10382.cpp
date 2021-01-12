#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
#define L first
#define R second
typedef pair<double, double> ii; 
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n, l, w;
  while(cin >> n >> l >> w) {
    vector<ii> arr;
    for(int i = 0; i < n; ++i) {
      double pos, rad;
      cin >> pos >> rad;
      if(rad > w/2.0) {
        double dx = sqrt(rad*rad - w*w/4.0);
        arr.push_back(ii(pos-dx, pos+dx));
      }
    }
    sort(arr.begin(), arr.end());
    double start = 0, s_used = 0;
    int index = 0;
    while(start < l) {
      double farthest = start;
      for(int i = index; i < arr.size(); ++i) {
        if(arr[i].L > start) break;
        farthest = max(farthest, arr[i].R);
        index = i;
      }
      if(farthest == start) break;
      start = farthest;
      ++s_used;
    }
    if(start < l)
      cout << -1 << "\n";
    else
      cout << s_used << "\n";
  }
}
