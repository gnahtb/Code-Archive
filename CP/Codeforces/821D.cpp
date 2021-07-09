#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int maxK = 10005;

int n, m, k, d[maxK], ans = LONG_MAX;
pii a[maxK];
bool f[maxK];
priority_queue<pii, vector<pii>, greater<pii>> q;

void dijkstra()
{
    memset(d, 1, sizeof d);
    memset(f, true, sizeof f);
    d[0] = 0;
    q.push({0, 0});
    while (!q.empty())
    {
        while (!q.empty() && !f[q.top().se]) q.pop();
        int idU = q.top().se; q.pop();
        for (int idV = 0; idV < k; ++idV) if (idU != idV && f[idV])
        {
            int t1 = abs(a[idU].fi - a[idV].fi), t2 = abs(a[idU].se - a[idV].se);
            if (t1 + t2 < 2 && d[idU] < d[idV])
            {
                d[idV] = d[idU];
                q.push({d[idV], idV});
            }
            else if ((t1 < 3 || t2 < 3) && d[idU] + 1 < d[idV])
            {
                d[idV] = d[idU] + 1;
                q.push({d[idV], idV});
            }
        }
    }
}

void solve()
{
    if (a[k - 1].fi == n && a[k - 1].se == m) { ans = d[k  - 1]; return; }
    for (int i = 0; i < k; ++i)
        if (abs(a[i].fi - n) < 2 || abs(a[i].se - m) < 2)
            ans = min(ans, d[i] + 1);
    if (ans > 30000) ans = -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) scanf("%d%d", &a[i].fi, &a[i].se);
    sort(a, a + k);
    dijkstra();
    solve();
    printf("%d\n", ans);
    return 0;
}
