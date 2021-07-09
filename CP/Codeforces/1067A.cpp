#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N_MAX = 1e5 + 5;
const int LIM = 200;
const ll MOD = 998244353;

int n, a[N_MAX];
ll f[2][3][LIM + 5], ans;

void solve() {
    if (a[1] < 0) {
        fill(f[1][0] + 1, f[1][0] + LIM + 1, 1);
    } else f[1][0][a[1]] = 1;
    for (int k = 0; k < 3; ++k)
        for (int j = 1; j <= LIM; ++j)
            (f[1][k][j] += f[1][k][j - 1]) %= MOD;
    for (int i = 2; i <= n; ++i) {
        memset(f[i & 1], 0, sizeof f[i & 1]);
        if (a[i] < 0) {
            for (int j = 1; j <= LIM; ++j) {
                (f[i & 1][0][j] += f[(i & 1) ^ 1][0][j - 1]) %= MOD;
                (f[i & 1][0][j] += f[(i & 1) ^ 1][1][j - 1]) %= MOD;
                (f[i & 1][0][j] += f[(i & 1) ^ 1][2][j - 1]) %= MOD;

                (f[i & 1][1][j] += f[(i & 1) ^ 1][0][j] - f[(i & 1) ^ 1][0][j - 1] + MOD) %= MOD;
                (f[i & 1][1][j] += f[(i & 1) ^ 1][1][j] - f[(i & 1) ^ 1][1][j - 1] + MOD) %= MOD;
                (f[i & 1][1][j] += f[(i & 1) ^ 1][2][j] - f[(i & 1) ^ 1][2][j - 1] + MOD) %= MOD;

                (f[i & 1][2][j] += f[(i & 1) ^ 1][1][LIM] - f[(i & 1) ^ 1][1][j] + MOD) %= MOD;
                (f[i & 1][2][j] += f[(i & 1) ^ 1][2][LIM] - f[(i & 1) ^ 1][2][j] + MOD) %= MOD;
            }
        } else {
            (f[i & 1][0][a[i]] += f[(i & 1) ^ 1][0][a[i] - 1]) %= MOD;
            (f[i & 1][0][a[i]] += f[(i & 1) ^ 1][1][a[i] - 1]) %= MOD;
            (f[i & 1][0][a[i]] += f[(i & 1) ^ 1][2][a[i] - 1]) %= MOD;

            (f[i & 1][1][a[i]] += f[(i & 1) ^ 1][0][a[i]] - f[(i & 1) ^ 1][0][a[i] - 1] + MOD) %= MOD;
            (f[i & 1][1][a[i]] += f[(i & 1) ^ 1][1][a[i]] - f[(i & 1) ^ 1][1][a[i] - 1] + MOD) %= MOD;
            (f[i & 1][1][a[i]] += f[(i & 1) ^ 1][2][a[i]] - f[(i & 1) ^ 1][2][a[i] - 1] + MOD) %= MOD;

            (f[i & 1][2][a[i]] += f[(i & 1) ^ 1][1][LIM] - f[(i & 1) ^ 1][1][a[i]] + MOD) %= MOD;
            (f[i & 1][2][a[i]] += f[(i & 1) ^ 1][2][LIM] - f[(i & 1) ^ 1][2][a[i]] + MOD) %= MOD;
        }
        for (int k = 0; k < 3; ++k)
            for (int j = 1; j <= LIM; ++j)
                (f[i & 1][k][j] += f[i & 1][k][j - 1]) %= MOD;
    }
    ans = (f[n & 1][1][LIM] + f[n & 1][2][LIM]) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("inp.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    solve();
    cout << ans << "\n";
    return 0;
}
