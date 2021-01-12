#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
int main()
{
  int TC, n;
  scanf("%d", &TC);
  for(int i = 0; i < TC; ++i)
  {
    int sum = 0;
    scanf("%d", &n);
    vi v(n);
    for(int i = 0; i < n; ++i)
      scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for(int i = 0; i < n-1; ++i)
      sum += v[i+1] - v[i];
    printf("%d\n", sum*2);
  }
  return 0;
}
