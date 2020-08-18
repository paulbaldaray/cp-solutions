#include <cstdio>
using namespace std;
const int xd[] = {1, 0, -1, 0};
const int yd[] = {0, 1, 0, -1};
const int grdsz = 52;
struct ii{bool exists; int val, cost;};
ii b[grdsz][grdsz]{};
int main() {
  int X, Y, w_cost, nb, bx, by, dir, lf, tot=0;
  scanf("%d%d%d%d", &X, &Y, &w_cost, &nb);
  while(nb--) {
    int x, y, val, cost;
    scanf("%d%d%d%d", &x, &y, &val, &cost);
    --x; --y;
    b[y][x] = {true, val, cost};
  } 
  while(scanf("%d%d%d%d", &bx, &by, &dir, &lf) != EOF) {
    int pts = 0; --bx; --by;
    while(--lf > 0) {
      int xn=bx+xd[dir], yn=by+yd[dir];
      if(xn <= 0 || xn >= X-1 || yn <= 0 ||yn >= Y-1) {
        lf -= w_cost;
        dir = (dir+3) % 4;
      }
      else if(b[yn][xn].exists) {
        pts += b[yn][xn].val;
        lf -= b[yn][xn].cost;
        dir = (dir+3) % 4;
      } 
      else {
        bx=xn; 
        by=yn;
      }
    }
    tot += pts;
    printf("%d\n", pts);
  }
  printf("%d\n",tot);
  return 0;
}
