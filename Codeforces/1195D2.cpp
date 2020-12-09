#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 2;
const int LIM = 11;
const ll MOD = 998244353;

int n;
ll a[N];
ll s[LIM][LIM], c[LIM];
ll ans;

int length(ll x) {
    int ret = 0;
    while (x > 0) {
        ++ret;
        x /= 10;
    }
    return ret;
}

void prep() {
    for (int i = 1; i <= n; ++i) {
        int len = length(a[i]);
        ++c[len];
        (s[len][0] += a[i]) %= MOD;
        ll t = a[i], b = 1, cr = 0;
        for (int i = 1; i <= len; ++i) {
            ll d = t % 10;
            t /= 10;
            (cr += d * b) %= MOD;
            (b *= 100) %= MOD;
            ll tc = (b * t % MOD + cr) % MOD;
            (s[len][i] += tc) %= MOD;
        }
    }
}

void solve(ll x) {
    int len = length(x);
    ll t = x, b = 10, cr = 0, i;
    for (i = 1; i <= len; ++i, (b *= 100) %= MOD) {
        ll d = t % 10;
        t /= 10;
        (cr += d * b) %= MOD;
        ll tc = (b * 10 * t % MOD + cr) % MOD;
        (ans += (s[i][i] + tc * c[i] % MOD) % MOD) %= MOD;
    }
    for (; i < LIM; ++i) {
        (ans += (s[i][len] + cr * c[i] % MOD) % MOD) %= MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    prep();
    for (int i = 1; i <= n; ++i) solve(a[i]);

    cout << ans << "\n";

    return 0;
}
