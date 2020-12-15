#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int N = 1e5 + 2;

struct IT {
    struct Node {
        int l, r;
        vector<pair<int, int>> v;
    } a[N << 3];

#define nx (i << 1)
#define md ((l + r) >> 1)
    void Build(int l, int r, int i = 1) {
        a[i].l = l;
        a[i].r = r;
        a[i].v.clear();
        if (l == r) return;
        Build(l, md, nx);
        Build(md + 1, r, nx + 1);
    }

    void Add(int p, int d, int vl, int i = 1) {
        if (a[i].l > p || a[i].r < p) return;
        a[i].v.emplace_back(d, vl);
        if (p == a[i].l && a[i].r == p) return;
        Add(p, d, vl, nx);
        Add(p, d, vl, nx + 1);
    }

    void Rebuild(int i = 1) {
        sort(a[i].v.begin(), a[i].v.end());
        for (int j = 1; j < sz(a[i].v); ++j) {
            a[i].v[j].second = min(a[i].v[j].second, a[i].v[j - 1].second);
        }
        if (a[i].l == a[i].r) return;
        Rebuild(nx);
        Rebuild(nx + 1);
    }

    int Query(int l, int r, int x, int i = 1) {
        if (a[i].l > r || a[i].r < l) return INT_MAX;
        if (l <= a[i].l && a[i].r <= r) {
            int vl = 0, vr = sz(a[i].v) - 1, vp = -1;
            while (vl <= vr) {
                int vm = (vl + vr) >> 1;
                if (a[i].v[vm].first <= x) {
                    vp = vm;
                    vl = vm + 1;
                } else {
                    vr = vm - 1;
                }
            }
            if (vp < 0) return INT_MAX;
            else return a[i].v[vp].second;
        }
        return min(Query(l, r, x, nx), Query(l, r, x, nx + 1));
    }
#undef nx
#undef md
} tree;

int n, r, a[N], depth[N];
vector<int> adj[N];
vector<int> tour;
vector<int> id[N];

void DFS(int u, int p) {
    tour.push_back(u);
    for (int v : adj[u]) if (v != p) {
        depth[v] = depth[u] + 1;
        DFS(v, u);
    }
    tour.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> r;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(r, 0);
    tree.Build(0, sz(tour) - 1);
    for (int i = 0; i < sz(tour); ++i) {
        if (id[tour[i]].empty()) {
            tree.Add(i, depth[tour[i]], a[tour[i]]);
        }
        id[tour[i]].push_back(i);
    }
    tree.Rebuild();
    int m, last = 0;
    cin >> m;
    while (m--) {
        int p, q;
        cin >> p >> q;
        int x = (p + last) % n + 1;
        int k = (q + last) % n;
        last = tree.Query(id[x][0], id[x][1], depth[x] + k);
        cout << last << "\n";
    }
    return 0;
}