#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 2, P = 20;
const ll MOD = 1e9 + 7;

int n, cnt[P + 2][3];
ll f[2][P + 2][3];

int exp(int x, int base) {
    int ret = 0;
    while (x % base == 0) ++ret, x /= base;
    return ret;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        ++cnt[exp(i, 2)][min(exp(i, 3), 1)];
    for (int i = P - 1; i >= 0; --i) {
        cnt[i][0] += cnt[i + 1][0] + cnt[i][1];
        cnt[i][1] += cnt[i + 1][1];
    }
    f[1][__lg(n)][0] = 1;
    f[1][__lg(n) - 1][1] = (1 << (__lg(n) - 1)) * 3 <= n;
    for (int i = 2; i <= n; ++i) {
        int c = i & 1, p = c ^ 1;
        memset(f[c], 0, sizeof f[c]);
        for (int j = 0; j < P; ++j) {
//            int tmp = cnt[j][0] - cnt[j][1];
            f[c][j][0] = f[p][j][1] * (cnt[j][0] - cnt[j][1]) % MOD;
            (f[c][j][0] += f[p][j + 1][0] * (cnt[j][0] - cnt[j + 1][0]) % MOD) %= MOD;
            (f[c][j][0] += f[p][j][0] * max(cnt[j][0] - i + 1, 0) % MOD) %= MOD;

            f[c][j][1] = f[p][j + 1][1] * (cnt[j][1] - cnt[j + 1][1]) % MOD;
            (f[c][j][1] += f[p][j][1] * max(cnt[j][1] - i + 1, 0) % MOD) %= MOD;
        }
    }
    cout << f[n & 1][0][0] << "\n";
    return 0;
}
