#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()
#define fi first
#define se second

typedef pair<int, int> ii;

const int N_MAX = 2E5 + 5;

int n, d[N_MAX], w[N_MAX];
bool vis[N_MAX];
vector<int> a[N_MAX];
vector<ii> b[N_MAX];

void dfs(int u, int x, int y) {
    if (sz(a[u]) > 2) {
        b[u].push_back({y, x});
        return;
    }
    vis[u] = true;
    for (int v : a[u]) if (!vis[v]) dfs(v, x, y + 1);
}

void longestPath(int &s, int &t, bool repeat) {
    queue<int> q;
    memset(d, -1, sizeof d);
    d[s] = 0; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : a[u]) if (d[v] < 0) q.push(v), d[v] = d[u] + 1;
    }
    int x = -1, y = -1, z = -1;
    for (int i = 1; i <= n; ++i) {
        if (sz(b[i]) < 2) continue;
        if (d[i] > y || (d[i] == y && w[i] > z))
            x = i, y = d[i], z = w[i];
    }
    if (repeat) {
        s = x;
        longestPath(s, t, false);
    } else t = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) cnt += sz(a[i]) > 2;
    for (int i = 1; i <= n; ++i) if (sz(a[i]) < 2) dfs(i, i, 0);
    for (int i = 1; i <= n; ++i) if (sz(b[i]) > 1) {
        sort(b[i].begin(), b[i].end(), greater<ii>());
        w[i] = b[i][0].fi + b[i][1].fi;
    }
    int s, y = -1, t = -1;
    for (int i = 1; i <= n; ++i)
        if (sz(b[i]) > 1 && w[i] > y) s = i, y = w[i];
    longestPath(s, t, true);
    cout << b[s][0].se << " " << b[t][0].se << "\n" << b[s][1].se << " " << b[t][1].se << "\n";
    return 0;
}
