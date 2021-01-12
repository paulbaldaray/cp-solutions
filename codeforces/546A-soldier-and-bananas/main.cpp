#include <iostream>
using namespace std;
int main () {
	long long k, n, w;
	cin >> k >> n >> w;
	cout << max(0LL, (w*(w+1)/2)*k - n) << '\n';
}
