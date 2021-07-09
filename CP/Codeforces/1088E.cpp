#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 3e5 + 5;

int n, cnt = 0;
ll a[N_MAX], f[N_MAX], f2[N_MAX], tmp = LLONG_MIN;
vector<int> adj[N_MAX];

void dfs1(int u, int p = 0) {
    f[u] = a[u];
    for (int v : adj[u]) if (v != p) {
        dfs1(v, u);
        f[u] += max(f[v], 0LL);
    }
    tmp = max(tmp, f[u]);
}

void dfs2(int u, int p = 0) {
    f[u] = a[u];
    for (int v : adj[u]) if (v != p) {
        dfs2(v, u);
        f[u] += max(f[v], 0LL);
    }
    if (f[u] == tmp) ++cnt, f[u] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1);
    dfs2(1);
    cout << tmp * cnt << " " << cnt << "\n";
    return 0;
}
