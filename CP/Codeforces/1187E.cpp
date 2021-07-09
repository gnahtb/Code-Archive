#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 2;

int n;
vector<int> a[N];
ll c[N], w[N], ans;

void dfs(int u, int p) {
    c[u] = 1;
    for (int v : a[u]) if (v != p) {
        dfs(v, u);
        w[u] += w[v];
        c[u] += c[v];
    }
    w[u] += c[u];
}

void dfs1(int u, int p, ll wp) {
    ll ws = 0;
    for (int v : a[u]) if (v != p) ws += w[v];
    ans = max(ans, n + ws + wp);
    for (int v : a[u]) if (v != p) {
        ll tmp = wp + ws - w[v] + n - c[v];
        dfs1(v, u, tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);
    dfs1(1, 0, 0);

    cout << ans << "\n";

    return 0;
}
