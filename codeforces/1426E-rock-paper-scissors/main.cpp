#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	long long N, a1, a2, a3, b1, b2, b3, diff, sum, wmax, wmin;
	cin >> N >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
	wmax = min(a1, b2) + min(a2, b3) + min(a3, b1);
	wmin = max(0LL, b1 - a1 - a2) + max(0LL, b2 - a2 - a3) + max(0LL, b3 - a3 - a1);
	cout << wmin << " " << wmax << '\n';
}
