#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int count_cheap(vector<int> &v) {
	int count = 0;
	for (int i = 1; i < (int)v.size()-1; ++i)
		if (v[i] < v[i-1] && v[i] < v[i+1])
			++count;
	return count;
}
void print(vector<int> &v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << (i+1 == v.size() ? '\n' : ' ');
}
int main() {
	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	vector<int> v1, v2;
	for (int i = N/2; i < N; ++i)
		v2.push_back(v.back()), v.pop_back();
	for (int i = 0; i < N/2; ++i)
		v1.push_back(v.back()), v.pop_back();
	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end(), greater<int>());
	for (int i = 0; i < N; ++i) {
		if (i % 2)
			v.push_back(v1.back()), v1.pop_back();
		else
			v.push_back(v2.back()), v2.pop_back();
	}
	cout << count_cheap(v) << '\n';
	print(v);
}
