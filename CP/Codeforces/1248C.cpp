#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int LIM = 1e5 + 2;
const ll MOD = 1e9 + 7;

int n, m;
ll f[LIM][2][5];

int main() {
    cin >> n >> m;
    f[1][0][1] = f[1][1][1] = 1;
    for (int i = 2; i <= max(m, n); ++i) {
        f[i][0][1] = (f[i - 1][1][1] + f[i - 1][1][2]) % MOD;
        f[i][0][2] = f[i - 1][0][1];
        f[i][1][1] = (f[i - 1][0][1] + f[i - 1][0][2]) % MOD;
        f[i][1][2] = f[i - 1][1][1];
    }
    ll tmp = (f[m][0][1] + f[m][0][2] + f[m][1][1] + f[m][1][2]) % MOD;
    ll ans = (tmp + MOD - 2) % MOD;
    tmp = (f[n][0][1] + f[n][0][2] + f[n][1][1] + f[n][1][2]) % MOD;
    (ans += tmp) %= MOD;
    cout << ans << "\n";
    return 0;
}
