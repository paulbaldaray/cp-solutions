#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
#define F first
#define S second
bool vstd[(int)2e4+5] = {false};
int main() {
	int N, M; cin >> N >> M;
	queue<ii> q;
	q.push({N, 0});
	while (!q.empty()) {
		ii x = q.front(); q.pop();
		if (x.F == M) {
			cout << x.S << '\n';
			break;
		}
		vstd[x.F] = true;
		if (x.F < M && !vstd[x.F*2])
			q.push({x.F*2, x.S+1});
		if (x.F > 1 && !vstd[x.F-1])
			q.push({x.F-1, x.S+1});
	}
}
