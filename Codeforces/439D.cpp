#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int limit = 1E5 + 5;

int n, m;
ll a[limit], b[limit], sA[limit], sB[limit], ans = LLONG_MAX;

void prep()
{
    memset(sA, 0, sizeof sA);
    memset(sB, 0, sizeof sB);
    for (int i = 1; i <= n; ++i) sA[i] = sA[i - 1] + a[i];
    for (int i = m; i > 0; --i) sB[i] = sB[i + 1] + b[i];
    a[++n] = 2E9; b[++m] = 2E9;
}

void solve()
{
    for (int i = 1; i < m; ++i)
    {
        auto it = lower_bound(a + 1, a + n + 1, b[i]);
        int p = distance(a, it) - 1;
        ll tmp = sB[i + 1] - sA[p] + b[i] * ll(p + i - m + 1);
        ans = min(ans, tmp);
    }
    for (int i = 1; i < n; ++i)
    {
        auto it = upper_bound(b + 1, b + m + 1, a[i]);
        int p = distance(b, it);
        ll tmp = sB[p] - sA[i - 1] + a[i] * ll(p + i - m - 1);
        ans = min(ans, tmp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for (int i = 1; i <= m; ++i) scanf("%lld", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    prep();
    solve();
    printf("%lld\n", ans);
    return 0;
}
