#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int mod = 1E9 + 7;

int n, m, f[2][505][505], d1, d2;
char c[505][505];

void prep()
{
    memset(f, 0, sizeof f);
    if ((n + m) % 2 != 0)
    {
        int t = (n + m + 2) >> 1;
        for (int row = 1; row <= min(n, t); ++row)
            if (row < t && t - row <= m)
            {
                int col = t - row;
                if (row < n && c[row][col] == c[row + 1][col]) ++f[t & 1][row][row + 1];
                if (col < m && c[row][col] == c[row][col + 1]) ++f[t & 1][row][row];
            }
        d1 = t - 1; d2 = t + 2;
    }
    else
    {
        int t = (n + m + 2) >> 1;
        for (int row = 1; row <= min(n, t); ++row)
            if (row < t && t - row <= m) f[t & 1][row][row] = 1;
        d1 = t - 1; d2 = t + 1;
    }
}

void solve()
{
    for (; d1 > 1; --d1, ++d2)
    {
        memset(f[d1 & 1], 0, sizeof f[d1 & 1]);
        for (int r1 = 1; r1 <= min(n, d1); ++r1) if (r1 < d1 && d1 - r1 <= m)
            for (int r2 = r1; r2 <= min(n, d2); ++r2) if (r2 < d2 && d2 - r2 <= m)
            {
                int c1 = d1 - r1, c2 = d2 - r2;
                if (c[r1][c1] != c[r2][c2]) continue;
                if (r1 < n && 0 < r2 && c[r1 + 1][c1] == c[r2 - 1][c2])
                    (f[d1 & 1][r1][r2] += f[(d1 + 1) & 1][r1 + 1][r2 - 1]) %= mod;
                if (r1 < n && 0 < c2 && c[r1 + 1][c1] == c[r2][c2 - 1])
                    (f[d1 & 1][r1][r2] += f[(d1 + 1) & 1][r1 + 1][r2]) %= mod;
                if (c1 < m && 0 < r2 && c[r1][c1 + 1] == c[r2 - 1][c2])
                    (f[d1 & 1][r1][r2] += f[(d1 + 1) & 1][r1][r2 - 1]) %= mod;
                if (c1 < m && 0 < c2 && c[r1][c1 + 1] == c[r2][c2 - 1])
                    (f[d1 & 1][r1][r2] += f[(d1 + 1) & 1][r1][r2]) %= mod;
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j) scanf("%c", &c[i][j]);
        scanf("\n");
    }
    prep();
    solve();
    printf("%d\n", f[0][1][n]);
    return 0;
}
