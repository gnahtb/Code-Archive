#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;
const int n_max = 1e6 + 5;

int n;
long long ans = 0, fact[n_max];

int main() {
    cin >> n;
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
    ans = fact[n];
    long long tmp = 1;
    for (int i = 1; i < n; ++i) {
        (tmp *= (long long)(n - i + 1)) %= MOD;
        (ans += tmp * ((fact[n - i] - 1 + MOD) % MOD) % MOD) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
