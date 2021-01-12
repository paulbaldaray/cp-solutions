#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <climits>
using namespace std;
#define F first
#define S second
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);
  int N, M;
  cin >> N >> M;
  vector<int> price(N);
  vector<vector<ii>> AdjList(N);
  for(int i = 0; i < N; ++i) cin >> price[i];
  for(int i = 0; i < M; ++i)
  {
    int u, v, d;
    cin >> u >> v >> d;
    AdjList[u].push_back({v, d});
    AdjList[v].push_back({u, d});
  }
  int TC, src, dst, cap;
  cin >> TC;
  while(TC-- && cin >> cap >> src >> dst)
  {
    int ans = -1;
    vector<vector<int>> dp(N, vector<int>(cap + 1, INT_MAX));
    dp[src][0] = 0;

    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({dp[src][0], {src, 0}});

    while(!pq.empty())
    {
      iii front = pq.top(); pq.pop();
      int c = front.F, u = front.S.F, g = front.S.S;

      if(u == dst)
      {
        ans = c;
        break;
      }

      //If not at a full tank and this is the cheapest way to get to this state
      if(g < cap && dp[u][g+1] > dp[u][g] + price[u])
      {
        //purchase 1 extra unit of fuel
        dp[u][g+1] = dp[u][g] + price[u];
        pq.push({dp[u][g+1], {u, g+1}});
      }
      
      for(int i = 0; i < (int) AdjList[u].size(); ++i)
      {
        int v = AdjList[u][i].F, d = AdjList[u][i].S;
        //If I have enough gas and the last way I got here was more expensive
        if(g >= d && dp[v][g-d] > dp[u][g])
        {
          //Go to the next city and spend the gas it takes to get there
          dp[v][g-d] = dp[u][g];
          pq.push({dp[v][g-d], {v, g-d}});
        }
      }
    }

    if(ans == -1) cout << "impossible\n";
    else cout << ans << "\n";
  }
}
