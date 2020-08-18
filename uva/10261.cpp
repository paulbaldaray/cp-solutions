#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int TC, x, ferry;
  cin >> TC;
  while(TC--) {
    cin >> ferry; ferry *= 100;
    vector<int> arr(1,0), arr_sums(1, 0);
    while(cin >> x && x) if(arr_sums.back() < ferry*2) {
        arr.push_back(x);
        arr_sums.push_back(arr_sums.back()+x);
    }
    vector<vector<bool>> reachable(arr.size(), vector<bool>(ferry+1, false));
    vector<vector<bool>> decision(arr.size(), vector<bool>(ferry+1, false));
    reachable[0][0] = true;
    int max_car = 0, end_v = 0; 
    for(int car = 1; car < arr.size(); ++car)
      for(int v1 = ferry; v1 >= 0; --v1)
        if(reachable[car-1][v1]) {
          if(arr[car] + v1 <= ferry) {
            max_car = car;
            end_v = arr[car]+v1;
            reachable[car][arr[car]+v1] = true;
            decision[car][arr[car]+v1] = false;
          }
          if(arr[car] + arr_sums[car-1] - v1 <= ferry) {
            max_car = car;
            end_v = v1;
            reachable[car][v1] = true;
            decision[car][v1] = true;
          }
        }
    cout << max_car << "\n";
    string log;
    while(max_car) {
      log = (decision[max_car][end_v]?"port\n":"starboard\n") + log;
      end_v -= (decision[max_car][end_v]? 0:arr[max_car]);
      --max_car;
    }
    cout << log;
    if(TC) cout << "\n";
  }
}
