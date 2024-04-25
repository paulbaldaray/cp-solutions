#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define TMID (tl + (tr - tl) / 2)
#define TLEFT (tn + 1)
#define TRIGHT (tn + 2 * (TMID - tl + 1))

const int MAX_N = 5000 + 10;
static bool tree[2*MAX_N + 5];

struct SegTree {
  int n;
  SegTree(int n) : n{n} {
    std::fill(tree, tree + 2*n + 5, false);
  }

  void prop(int tn, int tl, int tr) {
    if (tree[tn]) {
      tree[TLEFT] = tree[TLEFT] ^ tree[tn];
      tree[TRIGHT] = tree[TRIGHT] ^ tree[tn];
      tree[tn] = false;
    }
  }

  void build(const std::string &s) { return build(s, 0, 0, n - 1); }
  void build(const std::string &s, int tn, int tl, int tr) {
    if (tl == tr) {
      tree[tn] = s[tl] == '1';
    } else {
      build(s, TLEFT, tl, TMID);
      build(s, TRIGHT, TMID + 1, tr);
    }
  }

  bool query(int i) { return query(i, 0, 0, n - 1); }
  bool query(int i, int tn, int tl, int tr) {
    if (tl == tr) {
      return tree[tn];
    } else {
      prop(tn, tl, tr);
      if (i <= TMID) {
        return query(i, TLEFT, tl, TMID);
      } else {
        return query(i, TRIGHT, TMID + 1, tr);
      }
    }
  }

  void rangeInv(int lq, int rq) { rangeInv(lq, rq, 0, 0, n - 1); }
  void rangeInv(int lq, int rq, int tn, int tl, int tr) {
    if (rq < tl || tr < lq || rq < lq) {
      return;
    } else if (lq <= tl && tr <= rq) {
      tree[tn] = tree[tn] ^ true;
    } else {
      prop(tn, tl, tr);
      rangeInv(lq, rq, TLEFT, tl, TMID);
      rangeInv(lq, rq, TRIGHT, TMID + 1, tr);
    }
  }
};

int solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  for (int m = n; m > 0; --m) {
    SegTree segtree(n);
    segtree.build(s);

    for (int i = 0; i + m - 1 < n; ++i) {
      if (!segtree.query(i)) {
        segtree.rangeInv(i, i + m - 1);
      }
    }

    bool has_zero = false;
    for (int i = 0; i < n; ++i) {
      if (!segtree.query(i)) {
        has_zero = true;
        break;
      }
    }

    if (!has_zero) {
      return m;
    }
  }

  return 0;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
}
