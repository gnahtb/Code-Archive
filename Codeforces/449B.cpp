#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()
#define long long long
#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<long, int> li;

const int N_MAX = 1e5 + 5, M_MAX = 4e5 + 5;

int n, m, k, ans;
vector<ii> a[N_MAX];
long w[M_MAX], d[N_MAX];
bool chk[M_MAX];

priority_queue<li, vector<li>, greater<li>> q;
bool vis[N_MAX];
void dijkstra() {
    fill(d + 2, d + n + 1, LLONG_MAX);
    q.push({0, 1});
    while (!q.empty()) {
        int u = q.top().se; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = 0; i < sz(a[u]); ++i) {
            int v = a[u][i].fi, id = a[u][i].se;
            if (vis[v]) continue;
            if (d[v] > d[u] + w[id]) {
                d[v] = d[u] + w[id];
                q.push({d[v], v});
            }
        }
    }
}

int cnt = 0;
void dfs1(int u) {
    vis[u] = true;
    ++cnt;
    for (int i = 0; i < sz(a[u]); ++i) {
        int v = a[u][i].fi, id = a[u][i].se;
        if (vis[v] || chk[id]) continue;
        if (d[u] + w[id] == d[v]) dfs1(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v >> w[i];
        a[u].push_back({v, i}); a[v].push_back({u, i});
    }
    for (int i = m + 1; i <= m + k; ++i) {
        int v;
        cin >> v >> w[i];
        chk[i] = true;
        a[1].push_back({v, i}); a[v].push_back({1, i});
    }
    dijkstra();
    fill(vis + 1, vis + n + 1, false);
    dfs1(1);
    for (int i = 0; i < sz(a[1]); ++i) {
        int v = a[1][i].fi, id = a[1][i].se;
        if (!vis[v] && chk[id]) q.push({d[v], v});
    }
    while (cnt < n && !q.empty()) {
        int v = q.top().se;
        if (!vis[v]) {
            --k;
            dfs1(v);
        }
        q.pop();
    }
    cout << k << "\n";
    return 0;
}
