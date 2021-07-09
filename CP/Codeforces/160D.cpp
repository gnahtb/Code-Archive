#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sz(a) int(a.size())

typedef pair<int, int> ii;

struct TEdge { int u, v, w, x; };

const int lim = 1E5 + 5;

int n, m, c = 0, lab[lim], num[lim], low[lim];
TEdge e[lim];
bool vis[lim];
string ans[lim];
vector<ii> a[lim];

template <class T>
void minimize(T &a, T b) { if (a > b) a = b; }

int findSet(int u) { return lab[u] < 0 ? u : lab[u] = findSet(lab[u]); }

void makeSet(int r, int s) {
    if (lab[r] > lab[s]) swap(r, s);
    lab[r] += lab[s];
    lab[s] = r;
}

void findBridges(int u, int p) {
    num[u] = low[u] = ++c;

    for (int i = 0; i < sz(a[u]); ++i) {
        int v = a[u][i].fi, x = a[u][i].se;
        if (vis[x]) continue;
        if (!num[v]) {
            vis[x] = true;
            findBridges(v, u);
            minimize(low[u], low[v]);
            if (num[u] < low[v]) ans[x] = "any";
        } else minimize(low[u], num[v]);
    }
}

void solve() {
    fill(num, num + lim, 0);
    fill(lab, lab + lim, -1);
    for (int l = 0, r = 0; l < m; l = r) {
        vector<int> v;
        while (r < m && e[l].w == e[r].w) ++r;
        for (int i = l; i < r; ++i) {
            int r = findSet(e[i].u), s = findSet(e[i].v);
            if (r == s) { ans[e[i].x] = "none"; continue; }
            v.push_back(r); v.push_back(s);
            a[r].push_back({s, e[i].x}); a[s].push_back({r, e[i].x});
        }
        sort(v.begin(), v.end());
        v.resize(distance(v.begin(), unique(v.begin(), v.end())));
        for (int u: v) if (!num[u]) findBridges(u, -1);
        for (int i = l; i < r; ++i) {
            if (ans[e[i].x] == "none") continue;
            if (ans[e[i].x] != "any") ans[e[i].x] = "at least one";
            int r = findSet(e[i].u), s = findSet(e[i].v);
            if (r != s) makeSet(r, s);
        }
        for (int u: v) num[u] = low[u] = 0, a[u].clear();
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].x = i;
    }
    sort(e, e + m, [](TEdge a, TEdge b) { return a.w < b.w; });
    solve();
    for (int i = 0; i < m; ++i) cout << ans[i] << "\n";
}
