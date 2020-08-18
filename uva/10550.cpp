#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int one, two, three, four;
  while(scanf("%d %d %d %d", &one, &two, &three, &four)) {
    if(one == two && two == three && three == four && four == 0) break;
    double ans = 120.0;
    int n = two - one;
    ans += (n>=0)?40-n:-n;
    n = three - two;
    ans += (n<0)?40+n:n;
    n = four - three;
    ans += (n>=0)?40-n:-n;
    printf("%d\n", (int) (360.0*ans/40.0));
  }
  return 0;
}
