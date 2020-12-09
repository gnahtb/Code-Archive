#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll mod = 1E9 + 7;

int d, n, b[2005], i;
ll ans = 0;
vector<int> a[2005];
bool e[2005][2005];

ll DFS(int u, int p)
{
    if (b[u] == b[i]) e[u][i] = false;
    ll c = 1;
    for (int v: a[u]) if (v != p && b[i] <= b[v] && b[v] <= b[i] + d && e[i][v])
    {
        ll tmp = DFS(v, u);
        c = c * (tmp + 1) % mod;
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> d >> n;
    for (i = 1; i <= n; ++i) cin >> b[i];
    for (i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    memset(e, true, sizeof e);
    for (i = 1; i <= n; ++i) ans += DFS(i, 0), ans %= mod;
    cout << ans << "\n";
    return 0;
}
