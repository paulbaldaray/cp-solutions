#include <iostream>
using namespace std;
int main() {
	int N; cin >> N;
	bool a[200] = {false};
	for (int i = 0; i < 2; ++i) {
		int p; cin >> p;
		while (p--) {
			int x; cin >> x;
			a[x] = true;
		}
	}
	bool found = true;
	for (int i = 1; i <= N; ++i)
		if (!a[i])
			found = false;
	if (found)
		cout << "I become the guy.\n";
	else
		cout << "Oh, my keyboard!\n";
}
