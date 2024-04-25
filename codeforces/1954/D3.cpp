#include <bits/stdc++.h>
#define pb push_back
#define pob pop_back
 
using namespace std;
typedef long long ll;
typedef long double ldub;
 
const int MAXN = 5e3;
const int MOD = 1e9+7;
const int MODD = 998244353;
const ll INF = 1e18;
const int MAXB = 1<<18;
 
// dp[i]: number of subsets with sum i modulo MODD
ll dp[MAXN];
int a[MAXN];
 
void solve(int n) {
    // here, i'm using the edi's strategy
    // i actually have my own strategy which is a bit weirder, but i think it also works cuz of same concept
    for (int i = 0; i < MAXN; ++i) {
      dp[i] = 0;
    }
    dp[0]=1;
    // check if there are any odds
    bool od=false;
    int high = 0;
    int sum=0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        // cout << a[i] << endl;
        sum+=a[i];
        if (a[i]%2) od=true;
        // cout << a[i] << endl;
        high = max(high, a[i]);
    }

    /* std::cout << high << '\n'; */
    /* std::cout << sum << '\n'; */
    /* std::cout << od << '\n'; */

    for (int i = 0; i < n; ++i) {
      for (int j=high-a[i]-1;j>=0;j--) dp[j+a[i]]=(dp[j+a[i]]+dp[j])%MODD;
    }

    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    // for (int i=0;i<n;i++) cout << a[i] << endl;
    // now, instead of counting ceil(sum/2) contribution through the knapsack, we fast-count it
    // how? well, just do this: sum over all subset sums + number of subsets with odd sum and then divide everything by 2 :3
    // i mean, ceil(sum/2) is basically sum (if even sum) or sum + 1 (odd sum) and then divide by 2
    // also fun fact: the number of subsets with odd sum is either 0 or 2^(n-1). very weird ik
    ll mult=1;
    for (int i=0;i<n-2;i++) mult=(mult*2)%MODD;
    ll ans=((sum+od)*mult)%MODD;
    // cout << ans << endl;
    for (int i=0;i<n;i++) {
        // cout << a[i] << endl;
        for (int j=0;j<a[i]-1;j++) {
            ans=(ans+(a[i]-(a[i]+j+1)/2)*dp[j])%MODD;
            // cout << "k" << endl;
        }
    }
    cout << ans << endl;
}
 
int main() {
    int n;
    while (cin >> n) solve(n);
    return 0;
}
