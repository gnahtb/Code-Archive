#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9;

const int N_MAX = 1e5 + 5;

int n, f[N_MAX], ans = 0;

int main() {
    cin >> n;
    if (n > 0) {
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1, t = 1, x = 1; t <= i; ++j, t = j * (j * 3 - 1) / 2, x *= -1)
                (f[i] += (f[i - t] * x + MOD) % MOD) %= MOD;
            for (int j = -1, t = 2, x = 1; t <= i; --j, t = j * (j * 3 - 1) / 2, x *= -1)
                (f[i] += (f[i - t] * x + MOD) % MOD) %= MOD;
        }
        ans = f[n];
    }
    cout << ans << "\n";
    return 0;
}