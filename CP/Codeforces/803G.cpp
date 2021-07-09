#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

const int LG_MAX = 18, N_MAX = 1e5 + 5, Q_MAX = 1e5 + 5;
struct RMQ {
    int n, table[LG_MAX][N_MAX];

    void build(int _n, int *_a) {
        n = _n;
        for (int i = 1; i <= n; ++i) table[0][i] = _a[i];
        for (int j = 1, l = 1; j <= __lg(n); ++j, l <<= 1)
            for (int i = 1; i + l + l - 1 <= n; ++i)
                table[j][i] = min(table[j - 1][i], table[j - 1][i + l]);
    }

    int get_min(int l, int r) {
        int t = __lg(r - l + 1);
        return min(table[t][l], table[t][r - (1 << t) + 1]);
    }

    int query(int l, int r) {
        if (l > r) return INT_MAX;
        if (r - l + 1 >= n) return get_min(1, n);
        l -= (l - 1) / n * n;
        r -= (r - 1) / n * n;
        if (l > r) return min(get_min(l, n), get_min(1, r));
        return get_min(l, r);
    }
} rmq;

int n, k, q, b[N_MAX];
struct Query { int t, l, r, x = -1; } query[Q_MAX];
vector<int> p;

struct IntervalTree {
    const static int LIM = 3e6 + 5;
    struct Node {
        int il = -1, ir;
        int val = INT_MAX, lazy = -1;
    } a[LIM];

    inline void push(int i, int j) {
        if (a[i].lazy < 0 || a[j].il < 0) return;
        a[j].val = a[j].lazy = a[i].lazy;
    }

#define mid ((l + r) >> 1)
#define nxt (i << 1)
    inline void down(int i) {
        push(i, nxt);
        push(i, nxt + 1);
        a[i].lazy = -1;
    }

    void build(int l, int r, int i = 1) {
        a[i].il = p[l];
        a[i].ir = p[r + 1] - 1;
        a[i].val = rmq.query(a[i].il, a[i].ir);
        if (l == r) return;
        build(l, mid, nxt);
        build(mid + 1, r, nxt + 1);
    }

    void upd(int l, int r, int v, int i = 1) {
        if (a[i].il > r || a[i].ir < l) return;
        if (l <= a[i].il && a[i].ir <= r) {
            a[i].val = a[i].lazy = v;
            return;
        }
        down(i);
        upd(l, r, v, nxt);
        upd(l, r, v, nxt + 1);
        a[i].val = min(a[nxt].val, a[nxt + 1].val);
    }

    int query(int l, int r, int i = 1) {
        if (a[i].il > r || a[i].ir < l) return INT_MAX;
        if (l <= a[i].il && a[i].ir <= r) return a[i].val;
        down(i);
        int ret = min(query(l, r, nxt), query(l, r, nxt + 1));
        return ret;
    }
#undef mid
#undef nxt
} it;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    cin >> q;
    p.push_back(1);
    p.push_back(n * k + 1);
    for (int i = 1; i <= q; ++i) {
        cin >> query[i].t >> query[i].l >> query[i].r;
        if (query[i].t == 1) cin >> query[i].x;
        p.push_back(query[i].l);
        p.push_back(query[i].l + 1);
        p.push_back(query[i].l - 1);
        p.push_back(query[i].r);
        p.push_back(query[i].r + 1);
        p.push_back(query[i].r - 1);
    }
    sort(p.begin(), p.end());
    p.resize(distance(p.begin(), unique(p.begin(), p.end())));
    rmq.build(n, b);
    it.build(0, sz(p) - 2);
    for (int i = 1; i <= q; ++i)
        if (query[i].t == 1)
            it.upd(query[i].l, query[i].r, query[i].x);
        else
            cout << it.query(query[i].l, query[i].r) << "\n";
    return 0;
}
