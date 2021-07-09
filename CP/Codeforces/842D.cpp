#include <bits/stdc++.h>

using namespace std;

int n, m, c[20][524288], x = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    memset(c, 0, sizeof c);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        int a;
        scanf("%d", &a);
        if (c[0][a]) continue;
        for (int i = 0; i < 20; ++i) ++c[i][a >> i];
    }
    for (int i = 0; i < m; ++i)
    {
        int t, ans = 0;
        scanf("%d", &t);
        x ^= t;
        for (int i = 19; i >= 0; --i)
            if (c[i][(ans ^ x) >> i] == 1 << i)
                ans += 1 << i;
        printf("%d\n", ans);
    }
    return 0;
}
