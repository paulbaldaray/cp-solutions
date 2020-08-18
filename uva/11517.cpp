#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int n, TC, price, c, dp[15000]; 
int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin >> TC;
  while(TC-- && cin >> price >> n)
  {
    for(int i = 0; i < 15000; ++i) dp[i] = INT_MAX; dp[0] = 0;
    while(n-- && cin >> c)
      for(int v = 15000; v >= 0; --v)
        if(dp[v] != INT_MAX && v+c <= 15000 && dp[v+c] > dp[v]+1)
          dp[v+c] = dp[v]+1;
    for(int v = price; v <= 15000; ++v) if(dp[v] != INT_MAX)
    {
      cout << v << " " << dp[v] << "\n";
      break;
    }
  }
}
