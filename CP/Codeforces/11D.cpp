#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

int n, m;
ll f[524288][20], ans = 0;
bool e[20][20];

int getBit(int state, int index) { return (state >> index) & 1; }

void solve()
{
    memset(f, 0, sizeof f);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            f[(1 << i) + (1 << j)][j] = e[i][j];
    for (int mask = 1; mask < 1 << n; ++mask)
    {
        int s = 0, cnt = 0;
        for (; s < n; ++s) if (getBit(mask, s)) break;
        for (int i = 0; i < n; ++i) cnt += getBit(mask, i);
        if (cnt < 3) continue;
        for (int i = s + 1; i < n; ++i)
            for (int j = s + 1; j < n; ++j) if (e[i][j])
                f[mask][i] += f[mask ^ (1 << i)][j];
        for (int i = s + 1; i < n; ++i)
            if (getBit(mask, i) && e[s][i]) ans += f[mask][i];
    }
    ans >>= 1LL;
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    memset(e, false, sizeof e);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        e[u][v] = e[v][u] = true;
    }
    solve();
    printf("%lld\n", ans);
    return 0;
}
