#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 505;
const ll MOD = 998244353;

int n, k;
ll f[N_MAX][N_MAX], g[N_MAX], ans = 0;

void solve() {
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int s = 1; s <= n; ++s)
        for (int i = 1; i <= min(n, k); ++i) {
            if (s >= i) f[s][i] = f[s - i][i];
            for (int t = 0; t < i; ++t) {
                if (t && s >= t) (f[s][i] += f[s - t][i]) %= MOD;
                if (s >= i) (f[s][i] += f[s - i][t]) %= MOD;
            }
        }
    for (int i = 1; i <= min(n, k); ++i) g[i] = (g[i - 1] + f[n][i]) % MOD;
    for (int i = 1; i <= min(n, k); ++i) {
        int t = k / i - (!(k % i));
        (ans += f[n][i] * g[min(t, n)] % MOD) %= MOD;
    }
    (ans <<= 1LL) %= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    solve();
    cout << ans << "\n";
    return 0;
}
