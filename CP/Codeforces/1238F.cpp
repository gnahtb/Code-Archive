#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int N = 3e5 + 2;

int q, n, ans;
vector<int> a[N];

// 0 -> not root
int f[N];

void dfs(int u, int p = 0) {
    int mx1 = -1, mx2 = -1;
    for (int v : a[u]) if (v != p) {
        dfs(v, u);
        if (f[v] > mx1) {
            mx2 = mx1;
            mx1 = f[v];
        } else if (f[v] > mx2) mx2 = f[v];
    }
    int cnt = sz(a[u]) - 2;
    if (mx2 < 0) ++cnt, mx2 = 0;
    if (mx1 < 0) ++cnt, mx1 = 0;
    ans = max(ans, cnt + mx1 + mx2 + 1);
    int tmp = sz(a[u]) - 1;
    if (mx1 > 0) tmp += mx1 - 1;
    f[u] = tmp + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while (q--) {
        ans = 0;
        for (int i = 1; i <= n; ++i) a[i].clear();
        cin >> n;
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        dfs(1);
        cout << ans << "\n";
    }
    return 0;
}
