#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef vector<bool> vb;
vector<vb> matrix;
vector<bool> visited;
bool dfs(int start, int end, int skip)
{
  visited[start] = true;
  if(start == end) return true;
  bool hasFound = false;
  for(int i = 0; i < visited.size(); ++i)
    if(i != skip && !visited[i] && matrix[start][i])
      hasFound |= dfs(i, end, skip);
  return hasFound;
}

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);
  int TC, N, tc = 0;
  cin >> TC;
  while(tc++ < TC && cin >> N)
  {
    matrix = vector<vb>(N, vb(N));
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < N; ++j)
      {
        int x; cin >> x;
        matrix[i][j] = (x == 1);
      }
    string line = "+";
    for(int i = 0; i < N*2-1; ++i) line += "-"; 
    line += "+\n";
    cout << "Case " << tc << ":\n";
    cout << line;
    vb reachable(N);
    for(int i = 0; i < N; ++i)
    {
      visited = vb(N, false);
      reachable[i] = dfs(0, i, N);
    }
    for(int i = 0; i < N; ++i)
    {
      cout << "|";
      for(int j = 0; j < N; ++j)
      {
        visited = vb(N, false); 
        bool dominated = reachable[j] && (i == 0 || i == j || !dfs(0, j, i));
        cout << (dominated?"Y":"N") << "|";
      }
      cout << "\n" << line;
    }
  }
}
