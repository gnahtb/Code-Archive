#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int limit = 2E5 + 5;

int n, m, c = 0, u = 0, a[limit], b[limit];
pii p[limit], s[limit];

void solve()
{
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for (int d = 0; d < 31; ++d)
    {
        for (int i = 1, j = 1; i <= m; ++i) if (s[i].fi)
        {
            while (j <= n && (b[p[j].se] || p[j].fi < s[i].fi)) ++j;
            if (j <= n && s[i].fi == p[j].fi)
            {
                ++c; u += d;
                a[s[i].se] = d; b[p[j].se] = s[i].se;
                s[i].fi = 0;
            }
        }
        for (int i = 1; i <= m; ++i) (++s[i].fi) >>= 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i].fi), p[i].se = i;
    for (int i = 1; i <= m; ++i) scanf("%d", &s[i].fi), s[i].se = i;
    sort(p + 1, p + n + 1);
    sort(s + 1, s + m + 1);
    solve();
    printf("%d %d\n", c, u);
    for (int i = 1; i <= m; ++i) printf("%d ", a[i]);
    printf("\n");
    for (int i = 1; i <= n; ++i) printf("%d ", b[i]);
    return 0;
}
