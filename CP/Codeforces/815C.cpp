#include <bits/stdc++.h>

using namespace std;

template <typename T> void minimize(T &a, T b) { if (a > b) a = b; }

typedef long long ll;

const int maxN = 5005;
const ll inf = 1E15;

int n, c[maxN], d[maxN], s[maxN], ans;
ll b, f[maxN][maxN], g[maxN][maxN];
vector<int> a[maxN];

void solve()
{
    memset(s, 0, sizeof s);
    for (int u = n; u > 0; --u)
    {
        for (int i = 0; i <= n; ++i) f[u][i] = g[u][i] = inf;
        s[u] = 1;
        f[u][0] = 0; f[u][1] = c[u];
        g[u][1] = c[u] - d[u];
        for (int v: a[u])
        {
            for (int i = s[u]; i >= 0; --i)
                for (int j = 0; j <= s[v]; ++j)
                {
                    minimize(f[u][i + j], f[u][i] + f[v][j]);
                    minimize(g[u][i + j], g[u][i] + min(f[v][j], g[v][j]));
                }
            s[u] += s[v];
        }
    }
    for (ans = n; ans >= 0; --ans)
        if (min(f[1][ans], g[1][ans]) <= b) break;
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%lld", &n, &b);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &c[i], &d[i]);
        if (i > 1)
        {
            int x;
            scanf("%d", &x);
            a[x].push_back(i);
        }
    }
    solve();
    printf("%d\n", ans);
    return 0;
}
