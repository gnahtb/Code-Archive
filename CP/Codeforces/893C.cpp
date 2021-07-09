#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define long long long
#define init(a, b) memset(a, b, sizeof a)

const int maxN = 1e5 + 5;
const int inf = 1e9 + 5;

int n, m, id[maxN], p[maxN], c[maxN];
long ans = 0;
vector<int> a[maxN];

void BFS(int u, int x)
{
    queue<int> q;
    q.push(u);
    id[u] = x;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); ++i)
        {
            int v = a[u][i];
            if (id[v] == 0)
                q.push(v), id[v] = x;
        }
    }
}

void solve()
{
    init(id, 0);
    for (int i = 0; i <= maxN; ++i) p[i] = inf;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (id[i] == 0) BFS(i, ++cnt);
    for (int i = 1; i <= n; ++i) p[id[i]] = min(p[id[i]], c[i]);
    for (int i = 1; i <= cnt; ++i) ans += (long)p[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    solve();
    cout << ans;
    return 0;
}
