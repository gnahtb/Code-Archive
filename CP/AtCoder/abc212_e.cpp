#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5002, K = 5002;
const ll MOD = 998244353;

int n, m, k;
vector<int> a[N];
ll f[K][N];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    ll sum = 1;
    memset(f, 0, sizeof(f));
    f[0][1] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int u = 1; u <= n; ++u) {
            f[i][u] = (sum - f[i - 1][u] + MOD) % MOD;
            for (int v : a[u]) (f[i][u] += MOD - f[i - 1][v]) %= MOD;
        }
        sum = 0;
        for (int u = 1; u <= n; ++u) (sum += f[i][u]) %= MOD;
    }
    cout << f[k][1];
    return 0;
}