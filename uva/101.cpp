#include <iostream>
#include <string>
using namespace std;
const int MAX_BLOCKS = 25;
struct block{ int x,y; };
int table[MAX_BLOCKS][MAX_BLOCKS];
int height[MAX_BLOCKS];
block blocks[MAX_BLOCKS];
void return_blocks(int x, int start_y, int b_height) {
  for(int y = start_y; y < b_height; ++y)  {
    int curr = table[x][y];
    blocks[curr] = {curr, 0};
    ++height[curr];
    --height[x];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a, b;
  cin >> n;

  string mv, on;
  for(int i = 0; i < n; ++i) {
    table[i][0] = i;
    blocks[i] = {i, 0};
    height[i] = 1;
  }

  while(cin >> mv && mv != "quit" && cin >> a >> on >> b) {
    bool is_move = (mv == "move"), is_onto = (on == "onto");

    int bx = blocks[b].x, by = blocks[b].y;
    int ax = blocks[a].x, ay = blocks[a].y;
    
    if(ax == bx) continue;

    int a_height = height[ax], b_height = height[bx];

    if(is_onto)
      return_blocks(bx, by+1, b_height);

    blocks[a] = {bx, height[bx]};
    table[bx][height[bx]] = a;
    ++height[bx];
    --height[ax];

    if(is_move)
      return_blocks(ax,ay+1,a_height);
    else {
      for(int y = ay+1; y < a_height; ++y)
      {
        int curr = table[ax][y];
        table[bx][height[bx]] = curr;
        blocks[curr] = {bx, height[bx]};
        ++height[bx];
        --height[ax];
      }
    }
  }

  for(int x = 0; x < n; ++x) {
    cout << x << ":";
    for(int y = 0; y < height[x]; ++y)
      cout << " " << table[x][y];
    cout << "\n";
  }
 }
