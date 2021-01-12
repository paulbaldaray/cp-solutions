#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> a(N), sz(N), s;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	for (int i = 0; i < N; ++i) {
		while (!s.empty() && a[i] <= a[s.back()])
			s.pop_back();
		sz[i] += s.empty() ? i : i-s.back()-1;
		s.push_back(i);
	}
	s.clear();
	for (int i = N-1; i >= 0; --i) { 
		while (!s.empty() && a[i] <= a[s.back()])
			s.pop_back();
		sz[i] += s.empty() ? N-i-1 : s.back()-i-1;
		s.push_back(i);
	}
	s.assign(N, -1);
	for (int i = 0; i < N; ++i)
		if (s[sz[i]] == -1 || a[s[sz[i]]] < a[i])
			s[sz[i]] = i;
	for (int i = N-2; i >= 0; --i)
		if (s[i] == -1 || a[s[i]] < a[s[i+1]])
			s[i] = s[i+1];
	for (int i : s)
		cout << a[i] << ' ';
	cout << '\n';
}
