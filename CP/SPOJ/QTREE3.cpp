#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

#define sz(a) (int)a.size()
#define fi first
#define se second

struct IntervalTree {
    const static int LIM = 4e5 + 5;
    struct Node {
        int il, ir;
        ii val;

        inline void merge(Node &lhs, Node &rhs) {
            val = min(lhs.val, rhs.val);
        }
    } a[LIM];

#define mid ((l + r) >> 1)
#define nxt (i << 1)
    void build(int l, int r, int i = 1) {
        a[i].il = l;
        a[i].ir = r;
        if (l == r) return;
        build(l, mid, nxt);
        build(mid + 1, r, nxt + 1);
    }

    void update(int x, ii y, int i = 1) {
        if (a[i].il > x || a[i].ir < x) return;
        if (a[i].il == x && a[i].ir == x) {
            a[i].val = y;
            return;
        }
        update(x, y, nxt);
        update(x, y, nxt + 1);
        a[i].merge(a[nxt], a[nxt + 1]);
    }

    ii query(int l, int r, int i = 1) {
        if (a[i].il > r || a[i].ir < l)
            return {INT_MAX, INT_MAX};
        if (l <= a[i].il && a[i].ir <= r)
            return a[i].val;
        return min(query(l, r, nxt), query(l, r, nxt + 1));
    }
#undef mid
#undef nxt
};
struct HLD: IntervalTree {
    const static int LIM = 1e5 + 5;
    int ch[LIM], pr[LIM];
    int ccnt = 1, cid[LIM], chead[LIM];
    int pos[LIM];

    ii hquery(int u, int v) {
        if (cid[u] == cid[v])
            return query(pos[u], pos[v]);
        ii ret = query(pos[chead[cid[v]]], pos[v]);
        ret = min(ret, hquery(u, pr[chead[cid[v]]]));
        return ret;
    }
};
struct Tree: HLD {
    const static int LIM = 1e5 + 5;
    int nodes, dis[LIM];
    vector<int> adj[LIM];

    void init(int u = 1, int d = 0, int p = 0) {
        pr[u] = p;
        ch[u] = 1;
        dis[u] = d;
        for (int v : adj[u])
            if (v != p) {
                init(v, d + 1, u);
                ch[u] += ch[v];
            }
    }

    int step = 0;
    void decomp(int u = 1, int p = 0) {
        if (chead[ccnt] == 0) chead[ccnt] = u;
        cid[u] = ccnt;
        pos[u] = ++step;
        int nxt = -1;
        if (sz(adj[u]) > 1) {
            int pv = 0;
            for (int v : adj[u])
                if (v != p && pv < ch[v]) {
                    pv = ch[v];
                    nxt = v;
                }
            decomp(nxt, u);
        }
        for (int v : adj[u]) if (v != p && v != nxt) {
            ++ccnt;
            decomp(v, u);
        }
    }

    inline void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
} tree;

const int LIM = 1e5 + 5;

int q;
bool col[LIM];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("inp.txt", "r", stdin);
    cin >> tree.nodes >> q;
    for (int i = 1; i < tree.nodes; ++i) {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u, v);
    }
    tree.init();
    tree.decomp();
    tree.build(1, tree.nodes);
    for (int i = 1; i <= tree.nodes; ++i)
        tree.update(tree.pos[i], {INT_MAX, i});
    while (q--) {
        int t, u;
        cin >> t >> u;
        if (t == 0) {
            col[u] ^= 1;
            int val = col[u] ? tree.dis[u] : INT_MAX;
            tree.update(tree.pos[u], {val, u});
        } else {
            ii tmp = tree.hquery(1, u);
            int ans = tmp.fi == INT_MAX ? -1 : tmp.se;
            cout << ans << "\n";
        }
    }
    return 0;
}