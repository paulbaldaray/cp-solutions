#include <vector>
#include <iostream>

#define DEBUG

template <typename T>
std::ostream &operator<<(std::ostream &out, std::vector<T> v) {
  out << "{";
  for (int i = 0; i < v.size(); ++i) {
    std::cout << (i ? "," : "") << v[i];
  }
  return out << "}";
}

template <typename T, typename F, typename R>
std::vector<R> map(const std::vector<T> &v, F f) {
  std::vector<R> mv(v.size());
  for (int i = 0; i < v.size(); ++i) {
    mv[i] = f(v[i]);
  }
  return mv;
}
