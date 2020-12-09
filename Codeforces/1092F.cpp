#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 2;

int n;
ll a[N], s[N], cur, ans;
vector<int> ad[N];

void prep(int u = 1, int p = 0) {
    s[u] = a[u];
    for (int v : ad[u]) if (v != p) {
        prep(v, u);
        s[u] += s[v];
    }
    cur += s[u] - a[u];
}

void solve(int u = 1, int p = 0) {
    ans = max(ans, cur);
    for (int v : ad[u]) if (v != p) {
        ll tmp = s[1] - s[v] * 2;
        cur += tmp;
        solve(v, u);
        cur -= tmp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    prep();
    solve();
    cout << ans << "\n";
    return 0;
}
