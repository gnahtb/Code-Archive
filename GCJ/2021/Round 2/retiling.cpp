#include <bits/stdc++.h>

using namespace std;

const int N = 12;

struct HopcroftKarp
{
    const int INF = 1e9;
    int n;
    vector<int> d, matchL, matchR;
    vector<vector<int>> adj;
    HopcroftKarp(int n) : n(n), d(n + 1), matchL(n + 1), matchR(n + 1), adj(n + 1) {}

    // u is left vertex, v is right vertex
    void addEdge(int u, int v)
    {
        adj[u].emplace_back(v);
    }

    bool bfs()
    {
        queue<int> q;
        for (int u = 1; u <= n; ++u)
        {
            if (!matchL[u])
                d[u] = 0, q.emplace(u);
            else
                d[u] = INF;
        }
        d[0] = INF;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int &v : adj[u])
            {
                if (d[matchR[v]] == INF)
                {
                    d[matchR[v]] = d[u] + 1;
                    q.emplace(matchR[v]);
                }
            }
        }
        return d[0] != INF;
    }

    bool dfs(int u)
    {
        if (!u)
            return true;
        for (int &v : adj[u])
        {
            if (d[matchR[v]] == d[u] + 1 && dfs(matchR[v]))
            {
                matchR[v] = u;
                matchL[u] = v;
                return true;
            }
        }
        d[u] = INF;
        return false;
    }

    int calc()
    {
        int res = 0;
        while (bfs())
            for (int u = 1; u <= n; ++u)
                if (!matchL[u] && dfs(u))
                    ++res;
        return res;
    }
};

const int DR[4] = {1, 0, -1, 0};
const int DC[4] = {0, 1, 0, -1};

int test, r, c, f, s, ans;
char source[N][N], dest[N][N];
bool vis[N][N];

bool valid_cell(int i, int j)
{
    return 0 < i && i <= r && 0 < j && j <= c;
}

void solve()
{
    HopcroftKarp match(r * c);
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            cin >> dest[i][j];
            if (source[i][j] != dest[i][j])
            {
                ++ans;
                vis[i][j] = true;
            }
            else
                vis[i][j] = false;
        }
    }
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            if (!vis[i][j] || source[i][j] != 'M')
                continue;
            for (int k = 0; k < 4; ++k)
            {
                int i1 = i + DR[k], j1 = j + DC[k];
                if (!valid_cell(i1, j1) || !vis[i1][j1] || source[i1][j1] != 'G')
                    continue;
                match.addEdge((i - 1) * c + j, (i1 - 1) * c + j1);
            }
        }
    }
    ans -= match.calc();
}

int main()
{
    cin >> test;
    for (int itest = 1; itest <= test; ++itest)
    {
        cin >> r >> c >> f >> s;
        for (int i = 1; i <= r; ++i)
            for (int j = 1; j <= c; ++j)
                cin >> source[i][j];
        ans = 0;
        solve();
        cout << "Case #" << itest << ": " << ans << endl;
    }
    return 0;
}