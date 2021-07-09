#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define long long long
#define init(a, b) memset(a, b, sizeof a)

const long inf = 1e15;

int n, m, k, c[105], p[105][105];
long f[105][105][105], ans = inf;;

void solve()
{
    for (int i = 0; i < 105; ++i)
        for (int j = 0; j < 105; ++j)
            for (int l = 0; l < 105; ++l) f[i][j][l] = inf;
    if (c[1] == 0)
        for (int i = 1; i <= m; ++i) f[1][1][i] = p[1][i];
    else f[1][1][c[1]] = 0;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= k; ++j)
            if (c[i] == 0)
                for (int l = 1; l <= m; ++l)
                {
                    f[i][j][l] = f[i - 1][j][l] + p[i][l];
                    for (int q = 1; q <= m; ++q)
                        if (q != l) f[i][j][l] = min(f[i][j][l], f[i - 1][j - 1][q] + p[i][l]);
                }
            else
            {
                f[i][j][c[i]] = f[i - 1][j][c[i]];
                for (int l = 1; l <= m; ++l)
                    if (l != c[i]) f[i][j][c[i]] = min(f[i][j][c[i]], f[i - 1][j - 1][l]);
            }
    for (int l = 1; l <= m; ++l) ans = min(ans, f[n][k][l]);
    if (ans >= inf) ans = -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> p[i][j];
    solve();
    cout << ans;
    return 0;
}
