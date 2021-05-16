#include <bits/stdc++.h>

#define sz(a) (int)a.size()
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

const int LIM = 102;
int row, col;
char grid[LIM][LIM];
int idx[LIM][LIM], lk[LIM][LIM][2][2];

int towers, n, n1;
vector<int> sol, sol1, tin, fup, lb;
vector<pii> edges;
vector<bool> used;
vector<vector<int>> cp, g1, gr1;
vector<vector<pii>> g;

int node_idx(int u, int di, int neg) {
    int ret = u + (di + neg * 2) * towers;
    return ret;
}

int node_rev(int u) {
    if (u > n / 2) return u - n / 2;
    return u + n / 2;
}

void set_val(int idx, int val) {
    sol[idx] = val;
    sol[node_rev(idx)] = val ^ 1;
}

void enter() {
    cin >> row >> col;
    for (int i = 1; i <= row; ++i)
        for (int j = 1; j <= col; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'T') idx[i][j] = ++towers;
        }
}

void prep() {
    // horizontal
    for (int i = 1; i <= row; ++i) {
        function<void(int, int, int, int)> func = [&](int s, int f, int k, int d) {
            int t = -1;
            for (int j = s; j != f; j += d) {
                lk[i][j][0][k] = t;
                switch (grid[i][j]) {
                    case 'T': t = idx[i][j]; break;
                    case '#': t = -1; break;
                }
            }
        };
        func(1, col + 1, 0, 1);
        func(col, 0, 1, -1);
    }

    // vertical
    for (int j = 1; j <= col; ++j) {
        function<void(int, int, int, int)> func = [&](int s, int f, int k, int d) {
            int t = -1;
            for (int i = s; i != f; i += d) {
                lk[i][j][1][k] = t;
                switch (grid[i][j]) {
                    case 'T': t = idx[i][j]; break;
                    case '#': t = -1; break;
                }
            }
        };
        func(1, row + 1, 0, 1);
        func(row, 0, 1, -1);
    }
}

void build(int i, int j) {
    int cnt = 0;
    for (int d = 0; d < 2; ++d)
        for (int k = 0; k < 2; ++k)
            cnt += lk[i][j][d][k] > 0;
    switch (cnt) {
        case 1: {
            for (int d = 0; d < 2; ++d)
                for (int k = 0; k < 2; ++k) {
                    if (lk[i][j][d][k] < 0) continue;
                    set_val(node_idx(lk[i][j][d][k], d, 0), k);
                    return;
                }
            break;
        } case 2: {
            for (int k0 = 0; k0 < 2; ++k0)
                for (int k1 = 0; k1 < 2; ++k1)
                    if (lk[i][j][0][k0] > 0 && lk[i][j][1][k1] > 0) {
                        int u = node_idx(lk[i][j][0][k0], 0, k0 ^ 1);
                        int v = node_idx(lk[i][j][1][k1], 1, k1 ^ 1);
                        edges.emplace_back(node_rev(u), v);
                        edges.emplace_back(node_rev(v), u);
                        return;
                    }
            break;
        } case 3: {
            for (int d = 0; d < 2; ++d)
                if (lk[i][j][d][0] > 0 && lk[i][j][d][1] > 0) {
                    set_val(node_idx(lk[i][j][d][0], d, 0), 1);
                    set_val(node_idx(lk[i][j][d][1], d, 0), 0);
                    for (int k = 0; k < 2; ++k) {
                        if (lk[i][j][d ^ 1][k] < 0) continue;
                        set_val(node_idx(lk[i][j][d ^ 1][k], 1, 0), k);
                    }
                }
            break;
        }
    }
}

int tmr = 0;
stack<int> sk;
void dfs_scc(int u) {
    tin[u] = fup[u] = ++tmr;
    sk.push(u);

    for (int i = 0; i < sz(g[u]); ++i) {
        int v = g[u][i].fi, x = g[u][i].se;
        if (used[x]) continue;
        used[x] = true;
        if (tin[v] == 0) {
            dfs_scc(v);
            fup[u] = min(fup[u], fup[v]);
        } else
            fup[u] = min(fup[u], tin[v]);
    }

    if (tin[u] == fup[u]) {
        ++n1;
        while (true) {
            int ut = sk.top();
            sk.pop();
            tin[ut] = fup[ut] = INT_MAX;
            lb[ut] = n1;
            if (ut == u) break;
        }
    }
}

void dfs0(int u) {
    sol1[u] = 0;
    used[u] = true;
    for (int i : cp[u]) sol[i] = 0;
    for (int v : gr1[u]) if (!used[v]) dfs0(v);
}

void dfs1(int u) {
    if (used[u]) return;
    sol1[u] = 1;
    used[u] = true;
    for (int i : cp[u]) sol[i] = 1;
    for (int v : g1[u]) if (!used[v]) dfs1(v);
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (sol[i] == 0) {
            dfs0(lb[i]);
        } else if (sol[i] == 1) {
            dfs1(lb[i]);
        }
    }
    for (int i = 1; i <= n1; ++i)
        if (sol1[i] < 0) {
            sol1[i] = 1;
            used[i] = true;
            for (int u : cp[i]) sol[u] = 1;
            for (int u : cp[i]) dfs0(lb[node_rev(u)]);
        }
}

int main() {
    ios::sync_with_stdio(false);

    enter();
    n = towers * 4;
    prep();
    sol.assign(n + 2, -1);
    g.resize(n + 2);
    tin.assign(n + 2, 0);
    fup.assign(n + 2, 0);
    lb.assign(n + 2, 0);
    for (int i = 1; i <= row; ++i)
        for (int j = 1; j <= col; ++j)
            if (grid[i][j] == 'n') build(i, j);
            else if (grid[i][j] == 'T') {
                for (int d = 0; d < 2; ++d)
                    for (int k = 0; k < 2; ++k) {
                        if (lk[i][j][d][k] < 0) continue;
                        set_val(node_idx(lk[i][j][d][k], d, 0), k ^ 1);
                        set_val(node_idx(idx[i][j], d, 0), k);
                    }
            }
    used.assign(sz(edges), false);
    for (int i = 0; i < sz(edges); ++i)
        g[edges[i].fi].emplace_back(edges[i].se, i);
    for (int i = 1; i <= n; ++i)
        if (tin[i] == 0) dfs_scc(i);
    cp.resize(n1 + 2);
    g1.resize(n1 + 2);
    gr1.resize(n1 + 2);
    sol1.resize(n1 + 2, -1);
    used.assign(n1 + 2, false);
    for (int i = 1; i <= n; ++i) cp[lb[i]].push_back(i);
    for (pii i : edges) if (lb[i.fi] != lb[i.se]) {
        g1[lb[i.fi]].push_back(lb[i.se]);
        gr1[lb[i.se]].push_back(lb[i.first]);
    }
    solve();
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            if (grid[i][j] != 'T') {
                cout << grid[i][j];
                continue;
            }
            int u0 = node_idx(idx[i][j], 0, 0);
            int u1 = node_idx(idx[i][j], 1, 0);
            if (sol[u0] == 0)
                cout << ((sol[u1] == 0) ? 2 : 3);
            else
                cout << ((sol[u1] == 0) ? 1 : 4);
        }
        cout << "\n";
    }

    return 0;
}