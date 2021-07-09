#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int maxN = 2E5 + 5;

int n, m, k;
vector<int> e[maxN], p;
bool visited[maxN];

void DFS(int u)
{
    visited[u] = true;
    p.push_back(u);
    for (int i = 0; i < e[u].size(); ++i)
    {
        int v = e[u][i];
        if (!visited[v])
        {
            DFS(v);
            p.push_back(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(visited, false, sizeof visited);
    DFS(1);
    int d = (n * 2 - 1) / k + 1;
    for (int i = 0; i < k; ++i)
    {
        int l = min(i * d, (int)p.size() - 1), r = min((int)p.size() - 1, l + d - 1);
        cout << r - l + 1 << " ";
        for (int j = l; j <= r; ++j) cout << p[j] << " ";
        cout << "\n";
    }
    return 0;
}
