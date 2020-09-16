#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int v, f, b = 0;
	Edge(int v, int f) : v{v}, f{f} {}
};

int T = -1, S = -2;

int main() {
	int P, R, L;
	cin >> P >> R >> L;
	vector<vector<Edge>> adj;
	for (int i = 0; i < L; ++i) {
	}
}
