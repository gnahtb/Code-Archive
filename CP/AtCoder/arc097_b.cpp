#include <bits/stdc++.h>

using namespace std;

const int maxN = 1E5 + 5;

int n, m, p[maxN], d[maxN], ans = 0;
vector<int> a[maxN];

vector<int> BFS(int u, int x)
{
    queue<int> q;
    vector<int> t;
    q.push(u); t.push_back(u); d[u] = x;
    while (!q.empty())
    {
        u = q.front(); q.pop();
        for (int v: a[u]) if (!d[v])
            q.push(v), t.push_back(v), d[v] = x;
    }
    return t;
}

void solve()
{
    memset(d, 0, sizeof d);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (d[i]) continue;
        vector<int> v = BFS(i, ++cnt);
        for (int u: v) ans += (d[p[u]] == cnt);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v); a[v].push_back(u);
    }
    solve();
    printf("%d\n", ans);
    return 0;
}