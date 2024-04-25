struct SegTree {
    int n;
    std::vector<int> tree;
    SegTree(int n) : n{n}, tree(2*n-1) {}
    int min(int lq, int rq) { return min(lq, rq, 0, 1, n); }
    int min(int lq, int rq, int tn, int tl, int tr) {
        if (rq < tl || tr < lq || rq < lq) {
            return inf;
        } else if (lq <= tl && tr <= rq) {
            return tree[tn];
        } else {
            return std::min(
                    min(lq, rq, TLEFT, tl, TMID),
                    min(lq, rq, TRIGHT, TMID + 1, tr)
                );
        }
        return 0;
    }
    void update(int i, int v) { update(i, v, 0, 1, n); }
    void update(int i, int v, int tn, int tl, int tr) {
        if (tl == tr) {
            tree[tn] = v;
        } else {
            if (i <= TMID) {
                update(i, v, TLEFT, tl, TMID);
            } else {
                update(i, v, TRIGHT, TMID + 1, tr);
            }
            tree[tn] = std::min(tree[TLEFT], tree[TRIGHT]);
        }
    }
};
