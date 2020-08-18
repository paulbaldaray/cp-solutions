#include <string>
#include <cstdio>
using namespace std;
int main()
{
  int TC, sz;
  char c[200];
  string s;
  scanf("%d", &TC);
  for(int tc = 0; tc < TC; ++tc)
  {
    scanf("%s", c);
    s = c;
    sz = s.size();
    if(s=="1"||s=="4"||s=="78")
      printf("+\n"); 
    else if(sz>1&&s.substr(sz-2)=="35")
      printf("-\n");
    else if(sz>1&&s[0]=='9'&&s[sz-1]=='4')
      printf("*\n");
    else
      printf("?\n");
  }
}
