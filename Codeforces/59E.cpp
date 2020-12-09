#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;

const int maxN = 3005;

int n, m, k, d[maxN][maxN], t = -1;
ii p[maxN][maxN];
vector<int> a[maxN], b[maxN][maxN];

void BFS()
{
    queue<ii> q;
    memset(d, -1, sizeof d);
    memset(p, -1, sizeof p);
    for (int v: a[1]) q.push({v, 1}), d[v][1] = 1;
    while (!q.empty())
    {
        int x = q.front().fi, y = q.front().se;
        q.pop();
        if (x == n) { t = y; break; }
        for (int z: a[x])
        {
            if (binary_search(b[y][x].begin(), b[y][x].end(), z)) continue;
            if (d[z][x] > 0) continue;
            q.push({z, x});
            d[z][x] = d[x][y] + 1;
            p[z][x] = {x, y};
        }
    }
}

void trace()
{
    if (t == -1) { cout << "-1\n"; return; }
    stack<int> s;
    cout << d[n][t] << "\n"; 
    int u = n;
    while (u > 0 && t > 0)
    {
        s.push(u);
        int tmp = u;
        u = p[u][t].fi; t = p[tmp][t].se;
    }
    cout << "1 ";
    while (!s.empty()) cout << s.top() << " ", s.pop();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y); a[y].push_back(x);
    }
    for (int i = 0; i < k; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        b[x][y].push_back(z);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            sort(b[i][j].begin(), b[i][j].end());
    BFS();
    trace();
    return 0;
}
