#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

inline void Opt(int& a, int b) {
    if (a < b) a = b;
}

const int N = 5e5 + 2, LogN = 20;
const int M = 1e6 + 2;

int n, m, q;
int p[N][LogN], f[N][3][LogN][3], tin[N], tout[N];
vector<int> a[N], c[N];
pair<int, int> e[M];
bool used[N];

int tmr;
void DFS(int u) {
    tin[u] = ++tmr;

    // Iterate all edges
    for (int i : a[u]) {
        int v = e[i].first - u;
        if (v == p[u][0]) {
            c[u].push_back(e[i].second);
        } else if (p[v][0] == 0) {
            p[v][0] = u;
            DFS(v);
        }
    }

    // Remove unnecessary edges
    sort(c[u].begin(), c[u].end());
    c[u].erase(unique(c[u].begin(), c[u].end()), c[u].end());
    if (sz(c[u]) > 3) c[u].erase(c[u].begin() + 3, c[u].end());

    tout[u] = ++tmr;
}

void DFS1(int u) {
    used[u] = true;
    
    // Calculate
    for (int j = 0; j < sz(c[u]); ++j)
        for (int k = 0; k < sz(c[p[u][0]]); ++k)
            Opt(f[u][j][0][k], c[u][j] != c[p[u][0]][k]);
    for (int i = 1; i < LogN; ++i) {
        p[u][i] = p[p[u][i - 1]][i - 1];
        if (p[u][i] < 1) break;
        for (int j = 0; j < sz(c[u]); ++j)
            for (int k = 0; k < sz(c[p[u][i]]); ++k)
                for (int l = 0; l < sz(c[p[u][i - 1]]); ++l)
                    Opt(f[u][j][i][k], f[u][j][i - 1][l] + f[p[u][i - 1]][l][i - 1][k]);
    }

    for (int i : a[u]) {
        int v = e[i].first - u;
        if (u == p[v][0] && !used[v]) DFS1(v);
    }
}

int ft[3];
int Get(int u, int v, int (&vf)[3]) {
    memset(vf, 0, sizeof vf);
    for (int i = LogN - 1; i >= 0; --i) {
        if (p[u][i] < 1) continue;
        int tu = p[u][i];
        if (tin[tu] <= tin[v] && tout[v] <= tout[tu]) continue;
        memset(ft, 0, sizeof ft);
        for (int j = 0; j < sz(c[tu]); ++j)
            for (int k = 0; k < sz(c[u]); ++k)
                Opt(ft[j], vf[k] + f[u][k][i][j]);
        memcpy(vf, ft, sizeof ft);
        u = tu;
    }
    return u;
}

int fu[3], fv[3];
int Solve(int u, int v) {
    if (u == v || u == p[v][0] || v == p[u][0]) return 0;
    int tu = Get(u, v, fu);
    int tv = Get(v, u, fv);
    int ret = 0;
    if (u == 1 || u == p[tv][0] || v == p[tu][0]) {
        for (int i = 0; i < 3; ++i)
            Opt(ret, fu[i]), Opt(ret, fv[i]);
    } else {
        for (int i = 0; i < sz(c[tu]); ++i)
            for (int j = 0; j < sz(c[tv]); ++j) {
                // int tmp = fu[i] + fv[j] + (c[tu][i] != c[tv][j]);
                // if (c[tu][i] != c[tv][j]) ++tmp;
                Opt(ret, fu[i] + fv[j] + (c[tu][i] != c[tv][j]));
            }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[i] = {u + v, w};
        a[u].push_back(i);
        a[v].push_back(i);
    }
    DFS(1);
    DFS1(1);
    scanf("%d", &q);
    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", Solve(min(u, v), max(u, v)));
    }
    return 0;
}