#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
int main() {
	LL a, b;
	cin >> a >> b;
	LL n1 = (LL)sqrt(a);
	LL n2 = (LL)((-1LL + sqrt(1LL+4LL*b))/2LL);
	if (n1 <= n2)
		cout << "Vladik\n";
	else
		cout << "Valera\n";
}
