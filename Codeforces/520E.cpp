#include <bits/stdc++.h>

using namespace std;

#define odd(a) ((a) & 1)
#define sqr(a) (a) * (a)

typedef long long ll;

const int maxN = 100005;
const ll mod = 1000000007;

int n, k, a[maxN];
ll f[maxN], fi[maxN], u[maxN], ans = 0;

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
    for (ll i = 0, x = 1; i < n - k; ++i, (x *= 10LL) %= mod)
    {
        u[i] = x * nCr(n - i - 2, k - 1) % mod;
        if (i) (u[i] += u[i - 1]) %= mod;
    }
    for (int i = 1; i <= k; ++i) ans += ll(a[i]);
    (ans *= u[n - k - 1]) %= mod;
    for (ll i = n, x = 1; i > k; --i, (x *= 10LL) %= mod)
    {
        (ans += nCr(i - 1, k) * ll(a[i]) % mod * x % mod) %= mod;
        if (i < n) (ans += ll(a[i]) * u[n - i - 1] % mod) %= mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d\n", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        char ch;
        scanf("%c", &ch);
        a[i] = ch - '0';
    }
    prep();
    solve();
    printf("%lld\n", ans);
    return 0;
}
