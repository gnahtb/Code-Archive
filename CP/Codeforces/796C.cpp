#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int maxN = 3E5 + 5;

int n, a[maxN], d[maxN], ans = 2E9;
vector<int> adj[maxN];
priority_queue<pii, vector<pii>> q;

void solve()
{
    memset(d, 0, sizeof d);
    for (int u = 1; u <= n; ++u) q.push({a[u], u});
    for (int u = 1; u <= n; ++u)
    {
        int tmp = a[u];
        vector<int> b;
        d[u] = u; for (int v: adj[u]) d[v] = u, tmp = max(tmp, a[v] + 1);
        while (!q.empty() && d[q.top().se] == u) b.push_back(q.top().se), q.pop();
        if (!q.empty()) tmp = max(tmp, q.top().fi + 2);
        while (b.size()) q.push({a[b[b.size() - 1]], b[b.size() - 1]}), b.pop_back();
        ans = min(ans, tmp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int u = 1; u <= n; ++u)
        sort(adj[u].begin(), adj[u].end(), [](int x, int y) { return a[x] > a[y]; });
    solve();
    printf("%d\n", ans);
    return 0;
}
