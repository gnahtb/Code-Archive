#include <bits/stdc++.h>

using namespace std;

const int maxN = 1E6 + 5;
const int maxM = 1E5 + 5;

struct TCoor { int x, y; };

int n, m, sx[maxN], sy[maxN], u[maxN], cnt[maxN];
TCoor d, c[maxM];

void prep()
{
    sx[0] = sy[0] = 0;
    for (int i = 0; (i + d.x) % n; (i += d.x) %= n)
        sx[(i + d.x) % n] = sx[i] + 1;
    for (int i = 0; i < n; ++i) u[sx[i]] = i;
    for (int i = 0; (i + d.y) % n; (i += d.y) %= n)
        sy[(i + d.y) % n] = sy[i] + 1;
}

void solve()
{
    int ans = 0;
    for (int i = 0; i < m; ++i)
        ++cnt[u[(sx[c[i].x] - sy[c[i].y] + n) % n]];
    for (int i = 1; i < n; ++i)
        if (cnt[i] > cnt[ans]) ans = i;
    printf("%d 0\n", ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d%d%d", &n, &m, &d.x, &d.y);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", &c[i].x, &c[i].y);
    prep();
    solve();
    return 0;
}
