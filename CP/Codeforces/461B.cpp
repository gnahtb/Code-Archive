#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 1e5 + 5;
const ll MOD = 1e9 + 7;

int n;
bool x[N_MAX];
vector<int> a[N_MAX];
ll f[N_MAX][2];

ll power(ll x, ll y, ll z) {
    if (!y) return 1 % z;
    ll t = power(x, y / 2, z);
    (t *= t) %= z;
    if (y % 2 != 0) (t *= x) %= z;
    return t;
}

void solve(int u) {
    f[u][0] = x[u] ^ 1;
    f[u][1] = x[u];
    if (a[u].empty()) return;
    ll tmp = 1;
    for (int v : a[u]) {
        solve(v);
        (tmp *= f[v][0] + f[v][1]) %= MOD;
    }
    if (x[u]) {
        f[u][1] = tmp;
    } else {
        f[u][0] = tmp;
        for (int v : a[u]) {
            ll tmp1 = tmp * power(f[v][0] + f[v][1], MOD - 2, MOD) % MOD;
            (tmp1 *= f[v][1]) %= MOD;
            (f[u][1] += tmp1) %= MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        a[p].push_back(i);
    }
    for (int i = 0; i < n; ++i) cin >> x[i];
    solve(0);
    cout << f[0][1] << "\n";
    return 0;
}
