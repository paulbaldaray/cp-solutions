#include <cstdio>
using namespace std;
int TC, N, size, arr[500];
int main() {
  scanf("%d", &TC);
  while(TC-- && scanf("%d", &N)) {
    for(size = 0; size + 2 <= N; ++size) {
      arr[size] = size + 2;
      N-= size + 2;
    } 
    while(N)
      for(int i = size - 1; N && i >= 0; --i) {
        ++arr[i];
        --N;
      }
    for(int i = 0; i < size; ++i)
      printf("%d%c", arr[i], (i+1<size)?' ':'\n');
    if(TC)
      printf("\n");
  }
}
