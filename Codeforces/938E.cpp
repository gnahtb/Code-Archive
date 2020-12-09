#include <bits/stdc++.h>

using namespace std;

#define odd(a) ((a) & 1)
#define sqr(a) (a) * (a)

typedef long long ll;

const int maxN = 1000005;
const ll mod = 1000000007;

int n, a[maxN];
ll f[maxN], fi[maxN], ans = 0;

ll power(ll x, ll y)
{
    if (!y) return 1;
    ll tmp = power(x, y >> 1LL), ret = sqr(tmp) % mod;
    if (odd(y)) (ret *= x) %= mod;
    return ret;
}

void prep()
{
    f[0] = 1;
    for (ll i = 1; i <= n; ++i) f[i] = f[i - 1] * i % mod;
    fi[n] = power(f[n], mod - 2);
    for (ll i = n; i > 0; --i) fi[i - 1] = fi[i] * i % mod;
}

ll nCr(ll n, ll r)
{
    ll ret = f[n] * fi[r] % mod * fi[n - r] % mod;
    return ret;
}

void solve()
{
    bool flag = false;
    for (int L = 0, R = 0; L < n; L = R)
    {
        while (R < n && a[L] == a[R]) ++R;
        if (!flag) { flag = true; continue; }
        ll tmp = nCr(n, R) * f[R - 1] % mod * f[n - R] % mod;
        (ans += tmp * ll(R - L) % mod * ll(a[L]) % mod) %= mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n, greater<int>());
    prep();
    solve();
    printf("%lld\n", ans);
    return 0;
}
