#include <iostream>
#include <vector>
using namespace std;
int query(int i, int j) {
	cout << "? " << i << ' ' << j << '\n';
	cout.flush();
	int response; cin >> response;
	return response;
}
void answer(vector<int> &v) {
	cout << "! ";
	for (int i = 1; i < v.size(); ++i)
		cout << v[i] << (i+1 == v.size() ? '\n' : ' ');
	cout.flush();
}
int main() {
	int N; cin >> N;
	vector<int> ans(N+1, -1);
	int comp = 1;
	for (int i = 2; i <= N; ++i) {
		int r1 = query(comp, i), r2 = query(i, comp);
		if (r1 > r2)
			ans[comp] = r1, comp = i;
		else
			ans[i] = r2;
	}
	for (int i = 1; i <= N; ++i)
		if (ans[i] == -1) {
			ans[i] = N;
			break;
		}
	answer(ans);
}
