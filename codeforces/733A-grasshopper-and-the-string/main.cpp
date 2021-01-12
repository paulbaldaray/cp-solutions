#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	vector<bool> v(26, false);
	for (char c : string("AEIOUY"))
		v[c-'A'] = true;
	int ans = 1, curr = 1;
	for (char c : s) {
		if (v[c-'A'])
			ans = max(ans, curr), curr = 0;
		++curr;
	}
	cout << max(ans, curr) << '\n';
}
