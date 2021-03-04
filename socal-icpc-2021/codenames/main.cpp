#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <functional>
#include <map>
#include <set>
#include <cassert>
#define F first
#define S second
typedef double FT;
typedef std::pair<int, int> PII;
int main() {
	int N, M;
	char team;
	std::cin >> N >> team;
	std::map<std::string, int> code;
	for (int i = 1; i <= N; ++i) {
		std::string name;
		std::cin >> name;
		code[name] = i;
	}
	std::vector<char> type(N+1, ' ');
	for (int i = 1; i <= N; ++i)
		std::cin >> type[i];
	std::cin >> M;
	std::vector<std::vector<int>> hints(M+1);
	for (int i = 1, H; i <= M; ++i) {
		std::cin >> H;
		for (int j = 0; j < H; ++j) {
			std::string name;
			std::cin >> name;
			hints[i].push_back(code[name]);
		}
	}
	auto pbs = [&](int bs)->void{
		printf("%s(%d): ", (bs&1 ? "OPP": "TEAM"), bs);
		for (int i = 1; i <= N; ++i)
		if (bs&(1<<i))
				printf("%d ", i);
		printf("\n");
	};
	auto same_team = [&](char c, int bs) -> bool {
		if (c == 'A' || c == 'I')
			return false;
		return (team == c) ^ (bs & 1); // is_my_team ^ is_their_turn
	};
	auto count = [&](int bs, int h) {
		int c = 0;
		for (int w : hints[h])
			c += !(bs&(1 << w));
		return c;
	};
	auto hasWon = [&](int bs) {
		char c = same_team('R', bs) ? 'R' : 'B';
		bool ans = true;
		for (int i = 1; i <= N; ++i) {
			if (type[i] == c && !(bs&(1<<i)))
				ans = false;
			if (type[i] == 'A' && bs&(1<<i))
				return true;
		}
		return ans;
	};

	/* { */
		/* printf("I am on team %c.\n", team); */
		/* printf("The board consists of:\n"); */
		/* for (int i = 1; i <= N; ++i) */
		/* 	printf("%d%c\n", i, type[i]); */
		/* printf("These are the hints:\n"); */
		/* for (int i = 1; i <= M; ++i) { */
		/* 	printf("Hint %d: %d%c", i, hints[i][0], type[hints[i][0]]); */
		/* 	for (int j = 1; j < hints[i].size(); ++j) { */
		/* 		int w = hints[i][j]; */
		/* 		printf(", %d%c", w, type[w]); */
		/* 	} */
		/* 	printf("\n"); */
		/* } */
	/* } */

	/*dfjka sdjfkdsj*/

		std::map<int, FT> memo1;
		std::map<PII, FT> memo2;
		std::function<FT (int bs)> bestHint;
		std::function<FT (int bs, int h)> probHint;
		bestHint = [&](int bs) {
			if (memo1.count(bs))
				return memo1[bs];
			if (hasWon(bs))
				return memo1[bs] = 1.0;
			for (int h = 1; h <= M; ++h)
				if (count(bs, h))
					memo1[bs] = std::max(memo1[bs], probHint(bs, h));
			return memo1[bs];
		};
		probHint = [&](int bs, int h) {
			if (memo2.count(PII(bs, h)))
				return memo2[PII(bs, h)];
			if (hasWon(bs))
				return memo2[PII(bs, h)] = 1.0;
			if (count(bs, h) == 0)
				return memo2[PII(bs, h)] = 1-bestHint(bs^1);
			for (int w : hints[h]) if (!(bs&(1<<w))) {
				if (same_team(type[w], bs))
					memo2[PII(bs, h)] += probHint(bs|(1<<w), h);
				else
					memo2[PII(bs, h)] += 1-bestHint((bs|(1<<w))^1);
			}
			return memo2[PII(bs, h)]/count(bs, h);
		};
		std::cout << bestHint(0) << '\n';
}
