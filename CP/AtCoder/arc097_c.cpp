#include <bits/stdc++.h>
 
using namespace std;
 
const int lim = 4005;
 
int n, a[lim], b[lim], f[lim][lim], g[2][lim][lim];
 
template <typename T>
void minimize(T &a, T b) { if (a > b) a = b; }
 
void prep()
{
    memset(g, 0, sizeof g);
    for (int i = 1; i <= n + n; ++i)
    {
        for (int j = 1; j < i; ++j)
            if (b[i] != b[j]) ++g[b[i]][a[i]][a[j]];
            else if (a[j] > a[i]) ++g[b[i]][a[i]][n + 1];
        for (int j = n; j > 0; --j)
            g[b[i]][a[i]][j] += g[b[i]][a[i]][j + 1];
    }
}
 
void solve()
{
    memset(f, 0, sizeof f);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
        {
            if (!(i + j)) continue;
            f[i][j] = INT_MAX;
            if (i) minimize(f[i][j], f[i - 1][j] + g[0][i][j + 1]);
            if (j) minimize(f[i][j], f[i][j - 1] + g[1][j][i + 1]);
        }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d\n", &n);
    for (int i = 1; i <= n + n; ++i)
    {
        char c;
        scanf("%c%d\n", &c, &a[i]);
        b[i] = c == 'B' ? 0 : 1;
    }
    prep();
    solve();
    printf("%d\n", f[n][n]);
    return 0;
}