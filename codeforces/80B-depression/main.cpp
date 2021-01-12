#include <cstdio>
using namespace std;
int main() {
	int H, M; scanf("%d:%d", &H, &M);
	double hr = 360 / 12 * (H%12 + M/60.0), min = 360 / 60 * (M%60);
	printf("%f %f\n", hr, min);
}
