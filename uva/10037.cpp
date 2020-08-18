#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int TC, x, n, tm;
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin >> TC;
  while(TC-- && cin >> n) {
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
      cin >> arr[i];
    sort(arr.begin(), arr.end());
    tm = 0;
    stringstream result;
    if(n == 1) {
      tm = arr[0];
      result << arr[0] << "\n";
    }
    else {
      for(int i = n-2; i > 1; i-=2) {
        if(arr[1]*2 > arr[i]+arr[0]) {
          result << arr[0] << " " << arr[i] << "\n";
          result << arr[0] << "\n";
          result << arr[0] << " " << arr[i+1] << "\n";
          result << arr[0] << "\n";
          tm += arr[0]*2 + arr[i+1] + arr[i];
        }
        else {
          result << arr[0] << " " << arr[1] << "\n";
          result << arr[0] << "\n";
          result << arr[i] << " " << arr[i+1] << "\n";
          result << arr[1] << "\n";
          tm += arr[1]*2 +arr[i+1] + arr[0];
        }
      }
      result << arr[0] << " " << arr[1] << "\n";
      tm += arr[1];
      if(n%2) {
        result << arr[0] << "\n";
        result << arr[0] << " " << arr[2] << "\n";
        tm += arr[2] + arr[0];
      }
    }
    cout << tm << "\n" << result.str() << ((TC)?"\n":"");
  }
}
