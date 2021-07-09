#include <bits/stdc++.h>

using namespace std;

const int maxN = 1005;

int n, m, s, t, ans = 0, ds[maxN], dt[maxN];
bool avail[maxN];
vector<int> a[maxN];

void BFS(int s, int *d)
{
    queue<int> q;
    memset(d, 0, sizeof d);
    memset(avail, true, sizeof avail);
    q.push(s); avail[s] = false;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v: a[u]) if (avail[v])
        {
            q.push(v);
            d[v] = d[u] + 1;
            avail[v] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v); a[v].push_back(u);
    }
    BFS(s, ds);
    BFS(t, dt);
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            int w = min(ds[i] + dt[j] + 1, dt[i] + ds[j] + 1);
            if (w >= ds[t]) ++ans;
        }
    printf("%d\n", ans - m);
    return 0;
}
