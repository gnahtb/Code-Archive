#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
const int M = 2e5;

int test;
long long f[M + 100], inctime[M + 100];

void prep() {
    memset(f, 0, sizeof(f));
    memset(inctime, 0, sizeof(inctime));
    f[0] = 1;
    inctime[10] = 1;
    for (int i = 1; i <= M + 20; ++i) {
        f[i] = (f[i - 1] + inctime[i]) % MOD;
        (inctime[i + 10] += inctime[i]) %= MOD;
        (inctime[i + 9] += inctime[i]) %= MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    prep();
    cin >> test;
    while (test--) {
        int n, m;
        cin >> n >> m;
        long long ans = 0;
        while (n > 0) {
            (ans += f[n % 10 + m]) %= MOD;
            n /= 10;
        }
        cout << ans << "\n";
    }
    return 0;
}