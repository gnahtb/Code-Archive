#include <bits/stdc++.h>

using namespace std;

#define sqr(a) (a) * (a)
#define sz(a) int(a.size())

typedef long long ll;

const int lim = 2E5 + 5;

int n, a[lim], p[lim], lab[lim];
ll ans[lim];
vector<int> adj[lim], mul[lim];

template<typename T>
inline void fastRead(T &var)
{
    T sign = 1; var = 0;
    char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar())
        if (ch == '-') sign = -1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        var = var * 10 + ch - '0';
    var *= sign;
}

void sieve()
{
    for (int i = 2; i <= 2E5; ++i) p[i] = i;
    for (int i = 2; sqr(i) <= 2E5; ++i) if (p[i] == i)
        for (int j = sqr(i); j <= 2E5; j += i) p[j] = i;
}

void enter()
{
    int f[10], d[200] = { 1 }, n1, n2;
    fastRead(n);
    for (int i = 1; i <= n; ++i)
    {
        fastRead(a[i]);
        int x = a[i]; n1 = 0; n2 = 1;
        while (x > 1)
        {
            int t = p[x];
            f[n1++] = t;
            while (!(x % t)) x /= t;
        }
        for (int j = 0; j < n1; ++j)
            for (int k = 0; !(a[i] / d[k] % f[j]); ++k)
                d[n2++] = d[k] * f[j];
        for (int j = 0; j < n2; ++j) mul[d[j]].push_back(i);
    }
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        fastRead(u); fastRead(v);
        adj[u].push_back(v); adj[v].push_back(u);
    }
}

int DFS(int u, int x)
{
    int cnt = 1;
    lab[u] = x;
    for (int v: adj[u])
        if (lab[v] != x && !(a[v] % x)) cnt += DFS(v, x);
    return cnt;
}

void solve()
{
    for (int i = 2E5; i > 0; --i)
    {
        if (!sz(mul[i])) continue;
        ans[i] = sz(mul[i]);
        for (int u: mul[i]) if (lab[u] != i)
        {
            int cnt = DFS(u, i);
            ans[i] += (ll(cnt) * ll(cnt - 1)) >> 1LL;
        }
        for (int j = i + i; j <= 2E5; j += i) ans[i] -= ans[j];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    sieve();
    enter();
    solve();
    for (int i = 1; i <= 2E5; ++i)
        if (ans[i]) printf("%d %lld\n", i, ans[i]);
    return 0;
}
