#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define fi first
#define se second
#define sz(a) (int)a.size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int N = 1E5 + 5;

int n, m, k = 0, q, l[N], d[N], f[N];
ll s[N];
ii t[N][2];
vector<int> a[N], g[N];
map<ii, ld> h;

void calcDown(int u, int p) {
    t[u][0].fi = 0;
    for (int v : a[u]) if (v != p) {
        calcDown(v, u);
        if (t[v][0].fi >= t[u][0].fi) {
            t[u][1] = t[u][0];
            t[u][0] = {t[v][0].fi + 1, v};
        } else if (t[v][0].fi >= t[u][1].fi)
            t[u][1] = {t[v][0].fi + 1, v};
    }
}

void calcUp(int u, int p, int c) {
    l[u] = k;
    g[k].push_back(u);
    d[u] = max(c, t[u][0].fi);
    for (int v : a[u]) if (v != p)
        calcUp(v, u, max(c, v == t[u][0].se ? t[u][1].fi : t[u][0].fi) + 1);
}

void prep() {
    memset(t, -1, sizeof t);
    memset(d, -1, sizeof d);
    for (int u = 1; u <= n; ++u)
        if (t[u][0].fi < 0) calcDown(u, 0);
    for (int u = 1; u <= n; ++u)
        if (d[u] < 0) ++k, calcUp(u, 0, 0);
    for (int i = 1; i <= k; ++i) {
        sort(g[i].begin(), g[i].end(), [](int x, int y) { return d[x] > d[y]; });
        for (int j = 0; j < sz(g[i]); ++j) {
            f[i] = max(f[i], d[g[i][j]]);
            s[g[i][j]] = d[g[i][j]];
            if (j) s[g[i][j]] += s[g[i][j - 1]];
        }
    }
}

ld query(int u, int v) {
    ll sum = 0;
    int p = max(f[u], f[v]);
    if (sz(g[u]) > sz(g[v])) swap(u, v);
    for (int i : g[u]) {
        int l = 0, r = sz(g[v]) - 1, x = 0;
        while (l <= r) {
            int y = (l + r) >> 1;
            if (d[i] + d[g[v][y]] >= p) x = l = y + 1;
            else r = y - 1;
        }
        if (x) sum += s[g[v][x - 1]];
        sum += (ll)d[i] * x + x + (ll)(sz(g[v]) - x) * p;
    }
    return (ld)sum / sz(g[u]) / sz(g[v]);
}

int main() {
    ios_base::sync_with_stdio(false);
    (cout << fixed).precision(10);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    prep();
    for (int i = 1; i <= q; ++i) {
        int u, v;
        cin >> u >> v;
        u = l[u]; v = l[v];
        if (u == v) { cout << "-1\n"; continue; }
        if (u > v) swap(u, v);
        if (h.find({u, v}) == h.end()) h[{u, v}] = query(u, v);
        cout << h[{u, v}] << "\n";
    }
    return 0;
}
