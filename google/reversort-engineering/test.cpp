#include <cstdio>
#include <cmath>
int worstCost(int sz)
{
    int temp = (sz / 2) * (sz + 1);
    if (sz & 1)
        temp += static_cast<int>(std::ceil(sz / 2.0));
    return temp - 1;
}
int main() {
	for (int i = 1; i <= 100; ++i) 
		printf("%d: %d, %d\n", i, worstCost(i), (i-1)*(i+2)/2);
}
