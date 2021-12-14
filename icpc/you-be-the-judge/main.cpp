#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1024
int gchar() {
	static char buf[BUFFER_SIZE] = {0};
	static int ptr = 0;
	if (buf[ptr] == '\0') {
		if (fgets(buf, BUFFER_SIZE, stdin) == NULL)
			return EOF;
		ptr = 0;
	}
	return buf[ptr++];
}
bool isNumber(std::string& str) {
	for (auto &c : str)
		if (std::isdigit(c) == 0)
			return false;
	return true;
}
bool isInt(std::string &s) {
	if (s.empty() || strchr("-+0", s[0]))
		return false;
	if (!isNumber(s))
		return false;
	if (s.size() > 10)
		return false;
	else if (s.size() < 10)
		return true;
	else
		return s == "1000000000";
}
bool isPrime(int n) {
	if (n == 0 || n == 1)
		return false;
	for (int i = 2; i <= std::sqrt(n)+1 && i < n; ++i)
		if (n % i == 0)
			return false;
	return true;
}
bool tokenize(std::vector<std::string> &tokens) {
	bool inword = false;
	char c;
	while ((c = gchar()) != EOF) {
		bool ws = strchr(" \n\t\r\v\f", c);
		bool digit = c >= '0' && c <= '9';
		if (!ws && !digit)
			return false;
		if (!ws && !inword)
			tokens.push_back("");
		inword = !ws;
		if (!ws && inword)
			tokens.back() += c;
	}
	return true;
}

bool solve() {
	std::vector<std::string> tokens;
	if (!tokenize(tokens))
		return false;
	if (tokens.size() != 3)
		return false;
	std::vector<int> vals;
	for (auto &t : tokens)
		if (isInt(t))
			vals.push_back(std::stol(t));
	if (vals.size() != 3)
		return false;
	return vals[0] % 2 == 0 && vals[1] + vals[2] == vals[0] && isPrime(vals[1]) && isPrime(vals[2]);
}
int main() {
	std::cout << solve() << std::endl;
}
