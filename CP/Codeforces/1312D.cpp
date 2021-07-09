#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int LIM = 2e5;
const ll MOD = 998244353;

int n, m;
ll fa[LIM + 2], fai[LIM + 2], cn[LIM + 2];

ll Pow(ll x, ll y, ll z) {
    if (y == 0) return 1 % z;
    ll t = Pow(x, y >> 1, z);
    (t *= t) %= z;
    if ((y & 1) != 0) (t *= x) %= z;
    return t;
}

void Prep() {
    fa[0] = 1;
    for (int i = 1; i <= LIM; ++i) fa[i] = fa[i - 1] * i % MOD;
    fai[LIM] = Pow(fa[LIM], MOD - 2, MOD);
    for (int i = LIM; i; --i) fai[i - 1] = fai[i] * i % MOD;
}

ll nCr(ll n, ll r) {
    if (n < r) return 0;
    ll ret = fa[n] * fai[r] % MOD * fai[n - r] % MOD;
    return ret;
}

int main() {
    cin >> n >> m;
    if (n < 3) {
        cout << "0\n";
        return 0;
    }
    Prep();
    ll ans = nCr(m, n - 1) * (n - 2) % MOD;
    ll rep = Pow(2, n - 3, MOD);
    // for (int i = 2; i < n; ++i) {
    //     (rep += nCr(n - 3, i - 1)) %= MOD;
    // }
    (ans *= rep) %= MOD;
    cout << ans << "\n";
    return 0;
}
