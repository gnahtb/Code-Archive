#include <bits/stdc++.h>

using namespace std;

int n, a[2005], f[2][2005][2], ans = 0;

void prep()
{
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; ++i)
    {
        f[0][i][0] = f[0][i - 1][0];
        f[0][i][1] = f[0][i - 1][1];
        if (a[i] == 1) ++f[0][i][0];
        else f[0][i][1] = max(f[0][i][0], f[0][i][1]) + 1;
    }
    for (int i = n; i > 0; --i)
    {
        f[1][i][0] = f[1][i + 1][0];
        f[1][i][1] = f[1][i + 1][1];
        if (a[i] == 1) f[1][i][0] = max(f[1][i][0], f[1][i][1]) + 1;
        else ++f[1][i][1];
    }
}

void solve()
{
    for (int R = 1; R <= n; ++R)
    {
        int x = 0, y = 0;
        for (int L = R; L > 0; --L)
        {
            if (a[L] == 1) ++x;
            else y = max(x, y) + 1;
            int t1 = f[0][L - 1][0] + x + max(f[1][R + 1][0], f[1][R + 1][1]),
                t2 = max(f[0][L - 1][0], f[0][L - 1][1]) + y + f[1][R + 1][1];
            ans = max(ans, max(t1, t2));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    prep();
    solve();
    printf("%d\n", ans);
    return 0;
}
