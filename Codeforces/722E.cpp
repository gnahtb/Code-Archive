#include <bits/stdc++.h>

using namespace std;

#define odd(a) ((a) & 1)
#define sqr(a) (a) * (a)

typedef long long ll;

struct TCoor { int r, c; };

const int maxK = 2005;
const int limit = 200005;
const ll mod = 1000000007;

int n, m, k, s;
TCoor a[maxK];
ll f[limit], fi[limit], dp[maxK][20], ans = 0;

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
    for (int i = 1; i <= n + m; ++i)
        f[i] = f[i - 1] * ll(i) % mod;
    fi[n + m] = power(f[n + m], mod - 2);
    for (int i = n + m; i > 0; --i)
        fi[i - 1] = fi[i] * ll(i) % mod;
}

ll nCr(ll n, ll r)
{
    ll ret = f[n] * fi[r] % mod * fi[n - r] % mod;
    return ret;
}

void calc()
{
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < k; ++i)
    {
        fill(dp[i], dp[i] + 20, nCr(a[i].r + a[i].c - 2, a[i].r - 1));
        for (int j = 0; j < i; ++j)
            if (a[i].r >= a[j].r && a[i].c >= a[j].c)
            {
                ll w = nCr(a[i].r + a[i].c - a[j].r - a[j].c, a[i].r - a[j].r);
                for (int t = 0; t < 20; ++t)
                    (dp[i][t] += mod - w * dp[j][t] % mod) %= mod;
            }
        for (int t = 19; t > 0; --t)
            (dp[i][t] += mod - dp[i][t - 1]) %= mod;
    }
}

void solve()
{
    ans = nCr(n + m - 2, n - 1);
    for (int t = 0; t < 20; ++t)
    {
        (ans += (s - 1) * dp[k - 1][t] % mod) %= mod;
        (++s) >>= 1;
    }
    (ans *= power(nCr(n + m - 2, n - 1), mod - 2)) %= mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d%d%d", &n, &m, &k, &s);
    for (int i = 0; i < k; ++i)
        scanf("%d%d", &a[i].r, &a[i].c);
    sort(a, a + k, [](TCoor c1, TCoor c2) {
        if (c1.r == c2.r) return c1.c < c2.c;
        return c1.r < c2.r;
    });
    a[k++] = {n, m};
    prep();
    calc();
    solve();
    printf("%lld\n", ans);
    return 0;
}
