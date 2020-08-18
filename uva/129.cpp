#include <iostream>
#include <string>

using namespace std;

int n, L, x;
string seq(80, 0);

bool generate(int len) {
  if(x++ == n) {
    for(int i = 0; i < len; ++i) {
      if(i % 64 == 0 && i)
        cout << '\n';
      else if(i % 4 == 0 && i)
        cout << ' ';
      cout << seq[i];
    }
    cout << '\n' << len << '\n';
    return true;
  }
  ++len;
  for(char c = 'A'; c - 'A' < L; ++c) {
    seq[len - 1] = c;
    bool is_valid = true;
    for(int subsz = 1; is_valid && subsz*2-1 < len; ++subsz)
      for(int i = 0; is_valid && i+subsz*2-1 < len; ++i)
        is_valid = seq.substr(i, subsz) != seq.substr(i+subsz, subsz);
    if(is_valid && generate(len))
      return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  while(cin >> n >> L && (n != 0 || L != 0) ) {
    x = 0;
    generate(0);
  }
}
