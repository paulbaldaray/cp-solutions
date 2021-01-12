#include <iostream>
#include <string>
using namespace std;
int main() {
	int N; cin >> N;
	while (N--) {
		string s; cin >> s;
		if (s.size() <= 10)
			cout << s << '\n';
		else
			cout << s[0] << s.size()-2 << s[s.size()-1] << '\n';
	}
}
