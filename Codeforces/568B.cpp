#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int lim = 4005;
const ll mod = 1000000007;

int n;
ll c[lim][lim], g[lim];

void prep()
{
    memset(c, 0, sizeof c);
    for (int i = 0; i <= n; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
}

void solve()
{
    g[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        g[i] = (g[i - 1] << 1) % mod;
        for (int j = 1; j <= i; ++j)
            (g[i] += c[i - 1][j - 1] * g[i - j] % mod) %= mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d\n", &n);
    prep();
    solve();
    printf("%lld\n", g[n - 1]);
    return 0;
}
