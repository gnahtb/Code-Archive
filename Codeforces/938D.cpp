#include <bits/stdc++.h>

using namespace std;

#define long long long
#define fi first
#define se second

typedef pair<long, long> pll;

const int maxN = 2E5 + 5;

int n, m;
long p[maxN];
bool avail[maxN];
vector<pll> a[maxN];
priority_queue<pll, vector<pll>, greater<pll>> q;

void dijkstra()
{
    memset(avail, true, sizeof avail);
    for (long i = 1; i <= n; ++i) q.push({p[i], i});
    while (!q.empty())
    {
        while (!q.empty() && !avail[q.top().se]) q.pop();
        if (q.empty()) break;
        long u = q.top().se, d = q.top().fi;
        avail[u] = false;
        for (pll c: a[u])
        {
            long v = c.fi, w = c.se;
            if (avail[v] && d + w + w < p[v])
            {
                p[v] = d + w + w;
                q.push({p[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        long u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w}); a[v].push_back({u, w});
    }
    for (int i = 1; i <= n; ++i) cin >> p[i];
    dijkstra();
    for (int i = 1; i <= n; ++i) cout << p[i] << " ";
    cout << "\n";
    return 0;
}
