#include <iostream>
using uci = int;
#define int long long

const int MAX_N = 2e5;
int arr[MAX_N+10];
/* <> 10 9 */
/* <3 10 3 4 2 */
uci main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;

  arr[0] = 0;
  for (int i = 1; i <= MAX_N; ++i) {
    int x = 0;
    for (int y = i; y; y /= 10) {
      x += y % 10;
    }
    arr[i] = arr[i-1] + x;
  }

  while (t--) {
    int n;
    std::cin >> n;
    std::cout << arr[n] << '\n';
  }
}
