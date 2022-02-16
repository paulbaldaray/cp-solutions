#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>
#include <vector>

int N;
std::vector<int> tree, arr;

void build(int n, int l, int r) {
    if (l == r)
        tree[n] = arr[l];
    else {
        int m = l + (r-l)/2;
        build(n*2, l, m);
        build(n*2+1, m+1, r);
        tree[n] = std::gcd(tree[n*2], tree[n*2+1]);
    }
}

int query(int lq, int rq, int n, int l, int r) {
    if (r < lq || rq < l || r < l)
        return 0;
    else if (lq <= l && r <= rq)
        return tree[n];
    int m = l + (r-l)/2;
    return std::gcd(query(lq, rq, n*2, l, m), query(lq, rq, n*2+1, m+1, r));
}

int main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    std::cin >> N;
    arr.resize(N);
    tree.resize(N*4);
    for (int i = 0; i < N; ++i)
        std::cin >> arr[i];
    build(1, 0, N-1);
    std::vector<std::array<int, 3>> events;
    for (int i = 0; i < N; ++i) {
        int l = i, r = N-1;
        while (l < r) {
            int m = l + (r-l)/2;
            if (m - i + 1 >= query(i, m, 1, 0, N-1))
                r = m;
            else
                l = m + 1;
        }
        if (r - i + 1 == query(i, r, 1, 0, N-1)) {
            int id = events.size()/2;
            events.push_back({i, 0, id});
            events.push_back({r, 1, id});
        }
    }

    std::vector<bool> removed(events.size()/2, false);
    std::sort(events.begin(), events.end());
    std::vector<int> current, prefix(N);
    for (auto [i, t, id] : events)
        if (!removed[id]) {
            if (t == 0)
                current.push_back(id);
            else {
                prefix[i] = 1;
                while (!current.empty()) {
                    removed[current.back()] = true;
                    current.pop_back();
                }
            }
        }

    for (int i = 0, x = 0; i < N; ++i)
        std::cout << (x += prefix[i]) << (i+1 < N ? ' ' : '\n');
}
