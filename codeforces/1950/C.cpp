#include <iostream>
#include <string>
int main() {
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    int hour = std::stoi(s.substr(0, 2));
    std::string rest = s.substr(2);
    std::string half = hour < 12 ? "AM" : "PM";
    std::string shour = std::to_string(hour > 12 ? hour - 12 : hour == 0 ? 12 : hour);
    if (shour.size() < 2) {
      shour = "0" + shour;
    }
    std::cout << shour << rest << " " << half << '\n';
  }
}
