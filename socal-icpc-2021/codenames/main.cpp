#include <map>
#include <tuple>
#include <functional>
#define MEMOIZE(FName, RType, ...)\
std::function<RType (__VA_ARGS__)> _##FName;\
std::map<std::tuple<__VA_ARGS__>, RType> _memo_##FName;\
template <typename... Args>\
RType FName(Args... args){\
	auto state = std::make_tuple(args...);\
	if (_memo_##FName.count(state))\
			return _memo_##FName[state];\
	return _memo_##FName[state] = _##FName(args...);\
}

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
typedef double FT;

MEMOIZE(bestHint, FT, int);
MEMOIZE(probHint, FT, int, int);

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

		_bestHint = [&](int bs) {
			if (hasWon(bs))
				return 1.0;
			FT ans = 0.0;
			for (int h = 1; h <= M; ++h)
				if (count(bs, h))
					ans = std::max(ans, probHint(bs, h));
			return ans;
		};
		_probHint = [&](int bs, int h) {
			if (hasWon(bs))
				return 1.0;
			if (count(bs, h) == 0)
				return 1-bestHint(bs^1);
			FT ans = 0.0;
			for (int w : hints[h]) if (!(bs&(1<<w))) {
				if (same_team(type[w], bs))
					ans += probHint(bs|(1<<w), h);
				else
					ans += 1-bestHint((bs|(1<<w))^1);
			}
			return ans/count(bs, h);
		};
		std::cout << bestHint(0) << '\n';
}
