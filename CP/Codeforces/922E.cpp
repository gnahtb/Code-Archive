#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, c[1005], s = 0;
ll W, B, X, cost[1005], f[1005][10005];

inline void maximize(ll &p, ll q) { if (p < q) p = q; }

void solve()
{
    memset(f, -1, sizeof f);
    f[0][0] = W;
    for (int i = 1; i <= n; ++i)
    {
        f[i][0] = W;
        for (int j = 1; j <= s; ++j)
        {
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= min(j, c[i]); ++k)
                if (f[i - 1][j - k] >= cost[i] * k)
                    maximize(f[i][j], f[i - 1][j - k] - cost[i] * k);
            if (f[i][j] >= 0) f[i][j] = min(f[i][j] + X, W + B * j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%lld%lld%lld", &n, &W, &B, &X);
    for (int i = 1; i <= n; ++i) scanf("%d", &c[i]), s += c[i];
    for (int i = 1; i <= n; ++i) scanf("%lld", &cost[i]);
    solve();
    for (int i = s; i >= 0; --i)
        if (f[n][i] >= 0) { printf("%d\n", i); break; }
    return 0;
}
