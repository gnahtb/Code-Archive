#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;

struct TEdge { int u, v, w; };

const int N_MAX = 2e5 + 5, M_MAX = 2e5 + 5, LG_MAX = 18;

int n, m, ans[M_MAX], edge_id[M_MAX];
TEdge e[M_MAX];
vector<ii> a[N_MAX];
bool used[M_MAX];

// DSU;
int l[N_MAX];

// LCA and queries
int timer = 0, tin[N_MAX], tout[N_MAX];
int anc[LG_MAX][N_MAX], wmax[LG_MAX][N_MAX];

// HLD
int chain_cnt = 1, cur = 0;
int child_cnt[N_MAX], chain_head[N_MAX], chain_id[N_MAX], pos[N_MAX];

// Segment tree
int st[N_MAX << 2];

int root(int u) { return l[u] < 0 ? u : l[u] = root(l[u]); }

void unite(int s, int t) {
    if (l[s] > l[t]) swap(s, t);
    l[s] += l[t];
    l[t] = s;
}

void build_mst() {
    fill(l + 1, l + n + 1, -1);
    fill(used + 1, used + m + 1, false);
    for (int i = 1; i <= m; ++i) {
        TEdge t = e[edge_id[i]];
        if (root(t.u) != root(t.v)) {
            used[i] = true;
            unite(root(t.u), root(t.v));
            a[t.u].push_back({t.v, t.w});
            a[t.v].push_back({t.u, t.w});
        }
    }
}

void dfs(int u, int p) {
    tin[u] = ++timer;
    for (int i = 1; i < LG_MAX; ++i) {
        anc[i][u] = anc[i - 1][anc[i - 1][u]];
        wmax[i][u] = max(wmax[i - 1][u], wmax[i - 1][anc[i - 1][u]]);
    }
    for (ii i : a[u]) if (i.fi != p) {
        anc[0][i.fi] = u;
        wmax[0][i.fi] = i.se;
        dfs(i.fi, u);
        child_cnt[u] += child_cnt[i.fi] + 1;
    }
    tout[u] = ++timer;
}

void decompose(int u, int p) {
    if (!chain_head[chain_cnt]) chain_head[chain_cnt] = u;
    chain_id[u] = chain_cnt;
    pos[u] = ++cur;
    int x = -1;
    for (ii i : a[u])
        if (i.fi != p && (x == -1 || child_cnt[x] < child_cnt[i.fi])) x = i.fi;
    if (x > 0) decompose(x, u);
    for (ii i : a[u])
        if (i.fi != p && i.fi != x) ++chain_cnt, decompose(i.fi, u);
}

#define nxt (i << 1)
#define mid ((l + r) >> 1)
void st_upd(int v, int i, int l, int r, int xl, int xr) {
    if (l > xr || r < xl || xl > xr) return;
    if (xl <= l && r <= xr) { st[i] = min(st[i], v); return; }
    st_upd(v, nxt, l, mid, xl, xr);
    st_upd(v, nxt + 1, mid + 1, r, xl, xr);
    // st[i] = min(st[nxt], st[nxt + 1]);
}

int st_get(int i, int l, int r, int xl, int xr) {
    if (l > xr || r < xl || xl > xr) return INT_MAX;
    if (xl <= l && r <= xr) return st[i];
    int tmp = min(st_get(nxt, l, mid, xl, xr), st_get(nxt + 1, mid + 1, r, xl, xr));
    return min(st[i], tmp);
}
#undef nxt
#undef mid

void hld_upd(int w, int u, int v) {
    if (chain_id[u] == chain_id[v]) {
        st_upd(w, 1, 1, n, pos[u] + 1, pos[v]);
        return;
    }
    st_upd(w, 1, 1, n, pos[chain_head[chain_id[v]]], pos[v]);
    hld_upd(w, u, anc[0][chain_head[chain_id[v]]]);
}

int hld_get(int u, int v) {
    if (chain_id[u] == chain_id[v])
        return st_get(1, 1, n, pos[u] + 1, pos[v]);
    int ret = st_get(1, 1, n, pos[chain_head[chain_id[v]]], pos[v]);
    ret = min(ret, hld_get(u, anc[0][chain_head[chain_id[v]]]));
    return ret;
}

inline bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int get_lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = LG_MAX - 1; i >= 0; --i)
        if (anc[i][u] && !is_ancestor(anc[i][u], v)) u = anc[i][u];
    return anc[0][u];
}

void solve() {
    fill(st + 1, st + (n << 2), INT_MAX);
    for (int i = 1; i <= m; ++i) if (!used[i]) {
        TEdge t = e[edge_id[i]];
        int x = get_lca(t.u, t.v);
        hld_upd(t.w, x, t.u); hld_upd(t.w, x, t.v);
    }
    for (int i = 1; i <= m; ++i) {
        int sol = 0;
        TEdge t = e[edge_id[i]];
        if (used[i]) {
            if (!is_ancestor(t.u, t.v)) swap(t.u, t.v);
            sol = hld_get(t.u, t.v);
        } else {
            int cu = t.u, cv = t.v, x = get_lca(cu, cv);;
            for (int j = LG_MAX - 1; j >= 0; --j) {
                if (anc[j][cu] && is_ancestor(x, anc[j][cu]))
                    sol = max(sol, wmax[j][cu]), cu = anc[j][cu];
                if (anc[j][cv] && is_ancestor(x, anc[j][cv]))
                    sol = max(sol, wmax[j][cv]), cv = anc[j][cv];
            }
        }
        ans[edge_id[i]] = sol == INT_MAX ? -1 : sol - 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> e[i].u >> e[i].v >> e[i].w, edge_id[i] = i;
    sort(edge_id + 1, edge_id + m + 1, [](int& x, int& y) {
        return e[x].w < e[y].w;
    });
    build_mst();
    dfs(1, 0);
    decompose(1, 0);
    solve();
    for (int i = 1; i <= m; ++i) cout << ans[i] << " ";
    return 0;
}
