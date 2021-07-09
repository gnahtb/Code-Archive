#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, k, f[50005][505];
ll ans = 0;
vector<int> a[50005];

void DFS(int u, int p)
{
    f[u][0]=1;
    for (int v: a[u]) if (v != p)
    {
        DFS(v, u);
        for (int i = 1; i <= k; ++i) ans += ll(f[v][i - 1]) * ll(f[u][k - i]);
        for (int i = 1; i <= k; ++i) f[u][i] += f[v][i - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    memset(f, 0, sizeof f);
    DFS(1, 0);
    cout << ans << "\n";
    return 0;
}
