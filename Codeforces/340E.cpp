#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 1E9 + 7;

int n, a[2005];
bool chk[2005];
ll f[2005], c[2005][2005], ans = 0;

void enter()
{
    memset(chk, false, sizeof chk);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i] > 0) chk[a[i]] = true;
    }
}

void prep()
{
    memset(c, 0, sizeof c);
    memset(f, 0, sizeof f);
    f[0] = 1;
    c[0][0] = 1;
    for (int i = 1; i <= 2000; ++i)
    {
        f[i] = f[i - 1] * (ll)i % mod;
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
}

void solve()
{
    int u = 0, v = 0, p = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (!chk[i]) ++u;
        if (!chk[i] && (a[i] < 0)) ++v;
    }
    for (int i = 0; i <= v; ++i)
    {
        (ans += p * c[v][i] * f[u - i] + mod) %= mod;
        p = -p;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    enter();
    prep();
    solve();
    printf("%lld\n", ans);
    return 0;
}
