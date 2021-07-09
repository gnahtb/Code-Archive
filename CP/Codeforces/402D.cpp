#include <bits/stdc++.h>

using namespace std;

#define sqr(a) (a) * (a)

const int limit = 5005;

int n, m, a[limit], b[limit], g[limit], ans = 0;

int calc(int x)
{
    int r = 0;
    for (int i = 0; i < m; ++i)
        while (x % b[i] == 0) x /= b[i], --r;
    while (x > 1)
    {
        int d = x;
        for (int i = 2; sqr(i) <= x; ++i)
            if (x % i == 0) { d = i; break; }
        while (x % d == 0) x /= d, ++r;
    }
    return r;
}

void solve()
{
    g[0] = a[0];
    for (int i = 1; i < n; ++i) g[i] = __gcd(g[i - 1], a[i]);
    for (int i = n - 1; i >= 0; --i)
    {
        int t = calc(g[i]);
        if (t > 0) continue;
        for (int j = 0; j <= i; ++j) a[j] /= g[i], g[j] /= g[i];
    }
    for (int i = 0; i < n; ++i) ans += calc(a[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    solve();
    printf("%d\n", ans);
    return 0;
}
