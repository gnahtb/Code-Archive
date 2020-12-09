#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 1005;
const ll mod = 998244353;

int n, a[maxN];
ll c[maxN][maxN], f[maxN], ans;

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
    memset(f, 0, sizeof f);
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1];
        for (int j = 1; j < i; ++j)
            if (a[j] > 0 && a[j] <= i - j)
                (f[i] += c[i - j - 1][a[j] - 1] * f[j - 1] % mod) %= mod;
    }
    ans = (f[n] + mod - 1) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    prep();
    solve();
    cout << ans << "\n";
    return 0;
}
