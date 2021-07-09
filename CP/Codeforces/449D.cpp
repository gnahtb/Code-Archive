#include <bits/stdc++.h>

using namespace std;

const int L = 20;
const int LIM = 1 << L;
const long long MOD = 1e9 + 7;

int n, a[LIM + 5];
long long pw2[LIM + 5], f[LIM + 5], ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        ++a[t];
    }
    pw2[0] = 1;
    for (int i = 1; i < LIM; ++i)
        pw2[i] = pw2[i - 1] * 2LL % MOD;
    for (int i = 0; i < LIM; ++i)
        f[i] = pw2[a[LIM - i - 1]];
    for (int i = 0; i < L; ++i)
        for (int m = 0; m < LIM; ++m) {
            if (m >> i & 1)
                (f[m] *= f[m ^ (1 << i)]) %= MOD;
        }
    for (int i = 0; i < LIM; ++i)
        if ((L - __builtin_popcount(i)) & 1)
            (ans += MOD - f[i]) %= MOD;
        else
            (ans += f[i]) %= MOD;
    cout << ans << "\n";
    return 0;
}
