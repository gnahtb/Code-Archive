#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int maxN = 1E6 + 5;

int n, t[maxN], cnt[maxN][20][2];
ll ans = 0;
vector<int> a[maxN];

int get_bit(int state, int index) { return (state >> index) & 1; }

void DFS(int u, int p)
{
    ans += ll(t[u]);
    for (int i = 0; i < 20; ++i) ++cnt[u][i][get_bit(t[u], i)];
    for (int v: a[u]) if (v != p)
    {
        DFS(v, u);
        ll tmp = 1;
        for (int i = 0; i < 20; ++i)
        {
            ans += ll(cnt[u][i][1]) * ll(cnt[v][i][0]) * tmp;
            ans += ll(cnt[u][i][0]) * ll(cnt[v][i][1]) * tmp;
            cnt[u][i][get_bit(t[u], i) ^ 0] += cnt[v][i][0];
            cnt[u][i][get_bit(t[u], i) ^ 1] += cnt[v][i][1];
            tmp <<= 1LL;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    memset(cnt, 0, sizeof cnt);
    DFS(1, 1);
    cout << ans << "\n";
    return 0;
}
