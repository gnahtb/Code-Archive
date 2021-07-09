#include <bits/stdc++.h>

using namespace std;

#define sz(a) int(a.size())

const int maxN = 2E5 + 5;

int n, child = 0, f[maxN], g[maxN];
vector<int> a[maxN];

void DFS(int u)
{
    if (!sz(a[u])) { ++child; f[u] = g[u] = 1; return; }
    f[u] = INT_MAX; g[u] = 0;
    for (int v: a[u])
    {
        DFS(v);
        f[u] = min(f[u], g[v]);
        g[u] += f[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
    }
    DFS(1);
    printf("%d %d\n", child - f[1] + 1, g[1]);
    return 0;
}
