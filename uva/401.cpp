#include <string>
#include <iostream>
using namespace std;
#define middle word[n/2]
inline bool is_num(char c) { return c>47&&c<58; }
inline bool is_let(char c) { return c>64&&c<91; }
const string beta =  "A---3--HIL-JM-O---2TUVWXY5";
const string rev = "01SE-Z--8-";
int main()
{
  string word;
  while(cin >> word) {
    bool is_mirr=1, is_pal=1;
    int n = word.size();
    for(int i = 0; i < n/2; ++i)
    {
      char c1 = word[i], c2 = word[n-i-1];
      is_pal &= c1 == c2;
      if(is_let(c1))
        is_mirr &= beta[c1-'A'] == c2;
      else if(is_num(c1))
        is_mirr &= rev[c1-'0'] == c2;
    }
    if(n%2==1)
    {
      if(is_let(middle))
        is_mirr &= beta[middle-'A'] == middle;
      else if(is_num(middle))
        is_mirr &= rev[middle-'0'] == middle;
    }
    if(is_mirr && is_pal)
      cout << word << " -- is a mirrored palindrome.\n";
    else if(is_mirr)
      cout << word << " -- is a mirrored string.\n";
    else if(is_pal)
      cout << word << " -- is a regular palindrome.\n";
    else
      cout << word << " -- is not a palindrome.\n";
    cout << "\n";
  }
}
