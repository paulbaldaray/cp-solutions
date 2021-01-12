#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int q[8], TC, req_row, req_col, line_count;

void backtrack(int col)
{
  if(col == 8 && q[req_col] == req_row)
  {
    printf("%2d     ", ++line_count);
    for(int i = 0; i < 8; ++i)
      printf(" %d", q[i]+1);
    printf("\n");
  }
  for(int i = 0; i < 8; ++i)
  {
    bool is_valid = true;
    for(int j = col-1; is_valid && j >= 0; --j)
      is_valid = i != q[j] && abs(i-q[j]) != abs(col-j); 
    if(is_valid)
    {
      q[col] = i;
      backtrack(col+1);
    }
  }
}

int main()
{
  scanf("%d", &TC);
  while(TC--)
  {
    scanf("%d %d", &req_row, &req_col); --req_row; --req_col;
    memset(q, 0, sizeof q); line_count = 0;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    backtrack(0);
    if(TC)
      printf("\n");
  }
  return 0; 
}
