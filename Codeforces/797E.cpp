#include <bits/stdc++.h>

using namespace std;

#define sqr(a) (a) * (a)

const int maxN = 1E5 + 5;

int n, q, a[maxN], f[400][maxN];

void prep()
{
    memset(f, 0, sizeof f);
    for (int k = 1; k <= sqrt(n) + 10; ++k)
        for (int p = n; p > 0; --p)
        {
            f[k][p] = 1;
            if (p + a[p] + k <= n) f[k][p] += f[k][p + a[p] + k];
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    prep();
    scanf("%d", &q);
    while (q--)
    {
        int p, k;
        scanf("%d%d", &p, &k);
        if (k > sqrt(n) + 10)
        {
            int ans = 0;
            while (p <= n) ++ans, p += a[p] + k;
            printf("%d\n", ans);
        }
        else printf("%d\n", f[k][p]);
    }
    return 0;
}
