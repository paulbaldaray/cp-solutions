#include <cstdio>
using namespace std;

int main()
{
  char c[] = "0";
  bool f = false;
  while((*c = getchar()) != EOF)
    printf("%s",(*c!='"')?c:((f=!f)?"``":"''"));
}

