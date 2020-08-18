#include <cstdio>
#include <cstring>
using namespace std;
int coins[] = {2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};
unsigned long long dp[6010];
int main()
{
  memset(dp, 0, sizeof dp); dp[0] = 1;
  for(const int& c : coins)
    for(int p = 0; p <= 6000; ++p)
      if(dp[p] && p+c <= 6000)
        dp[p+c] += dp[p]; 
  double init_price;
  while(scanf("%lf", &init_price) && init_price)
    printf("%6.2lf%17lld\n", init_price, dp[int(init_price * 20.0 + .5)]);
}
