#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 1e5 + 5;

int n;
ll s[N_MAX], a[N_MAX];
vector<int> adj[N_MAX];

void dfs(int u, ll c) {
    if (s[u] >= 0) {
        a[u] = s[u] - c;
        for (int v : adj[u]) dfs(v, s[u]);
    } else {
        a[u] = LLONG_MAX;
        for (int v : adj[u]) {
            a[u] = min(a[u], s[v] - c);
        }
        if (a[u] < 0) {
            cout << "-1\n";
            exit(0);
        }
        if (a[u] == LLONG_MAX) a[u] = 0;
        for (int v : adj[u]) dfs(v, c + a[u]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i) cin >> s[i];
    dfs(1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans += a[i];
    cout << ans << "\n";
    return 0;
}
