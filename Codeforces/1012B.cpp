#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

int n, m, q;
vector<pair<int, int>> e;
vector<vector<int>> a;
vector<bool> used;

void dfs(int u) {
    used[u] = true;
    for (int v : a[u]) if (!used[v]) dfs(v);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> q;
    a.resize(n + m + 2);
    for (int i = 1; i <= q; ++i) {
        int u, v;
        cin >> u >> v;
        v += n;
        e.emplace_back(u, v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    used.assign(n + m + 2, false);
    int ans = -1;
    for (pair<int, int> i : e) {
        if (used[i.first] || used[i.second]) continue;
        if (sz(a[i.first]) > 1 && sz(a[i.second]) > 1) {
            ++ans;
            dfs(i.first);
        }
    }
    for (int i = 1; i <= n + m; ++i)
        if (!used[i]) dfs(i), ++ans;
    cout << ans << endl;
    
    return 0;
}
