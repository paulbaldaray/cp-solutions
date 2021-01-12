#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char **argv) {
	vector<string> args(argv, argv+argc);
	if (args.size() < 3)
		return 1;
	int N = stoi(args[1]), K = stoi(args[2]);
	vector<bool> is_prime(N+20, true);
	unordered_map<int, int> primes;
	for (int i = 2; i <= N; ++i) {
		if (is_prime[i])
			primes[i] = 1;
		for (int j = i+i; j <= N; j+=i)
			is_prime[j] = false;
	}
}
