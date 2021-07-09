#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int n, p[N], ans = 1;
bool c[N], vis[N];
vector<int> a[N];

vector<pair<int, int>> e;
vector<int> _a[N];

int f[N];

void dfs(int u, int x) {
    p[u] = x;
    vis[u] = true;
    for (int v : a[u]) if (!vis[v] && c[u] == c[v]) dfs(v, x);
}

void dfs1(int u, int x = 0) {
    for (int v : a[u]) if (v != x) {
        if (p[u] != p[v]) e.emplace_back(p[u], p[v]);
        dfs1(v, u);
    }
}

void solve(int u = 1, int x = 0) {
//    bool leaf = true;
    int mx1 = 0, mx2 = 0;
    for (int v : _a[u]) if (v != x) {
//        leaf = false;
        solve(v, u);
        if (f[v] > mx1) {
            mx2 = mx1;
            mx1 = f[v];
        } else if (f[v] > mx2) mx2 = f[v];
    }
    f[u] = mx1 + 1;
    ans = max(ans, mx1 + mx2 + 1);
}

int main() {
    ios::sync_with_stdio(false);
//    freopen("inp.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i, i);
    dfs1(1);
    for (pair<int, int> i : e) {
        _a[i.first].push_back(i.second);
        _a[i.second].push_back(i.first);
    }
    solve();
    --ans;
    cout << (ans / 2 + ans % 2) << "\n";
    return 0;
}
