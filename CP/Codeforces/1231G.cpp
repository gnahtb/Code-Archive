#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using ll = long long;

const int N = 1e5 + 2;
const ll MOD = 1e9 + 7;

int n;
ll x[N], ans;
vector<int> a[N];
map<ll, int> m[N];

void dfs(int u, int p = 0) {
    m[u][x[u]] = 1;
    (ans += x[u]) %= MOD;
    for (pair<ll, int> i : m[p]) {
        ll tmp = __gcd(i.fi, x[u]);
        (ans += tmp * i.se % MOD) %= MOD;
        m[u][tmp] += i.se;
    }
    for (int v : a[u]) if (v != p) dfs(v, u);
    m[u].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    cout << ans << "\n";
    return 0;
}
