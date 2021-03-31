#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
const int N = 1002;

int test, n, k;
long long f[N][N][2], fs[N][N][2];

int main() {
    cin >> test;
    while (test--) {
        cin >> n >> k;
        if (k == 1) {
            cout << "1\n";
            continue;
        }
        memset(f, 0, sizeof(f));
        memset(fs, 0, sizeof(fs));
        // for (int i = 1; i <= n; ++i) f[1][i][0] = f[1][i][1] = 1;
        for (int decay = 2; decay <= k; ++decay) {
            for (int wall = 1; wall <= n; ++wall) {
                f[decay][wall][0] = ((fs[decay - 1][n][1] - fs[decay - 1][wall][1] + n - wall) % MOD + MOD) % MOD;
                f[decay][wall][1] = ((fs[decay - 1][wall - 1][0] + wall - 1) % MOD + MOD) % MOD;
                fs[decay][wall][0] = (fs[decay][wall - 1][0] + f[decay][wall][0]) % MOD;
                fs[decay][wall][1] = (fs[decay][wall - 1][1] + f[decay][wall][1]) % MOD;
            }
        }
        long long ans = 1;
        for (int i = 1; i <= n; ++i) (ans += (f[k - 1][i][1] + 1)) %= MOD;
        cout << ans << "\n";
    }
    return 0;
}