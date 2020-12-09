#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct TEdge { int u, v, w; };

const int lim = 1000005;

int n, a[lim], l[lim];
TEdge e[lim];
ll ans = 0;

int findSet(int u) { return l[u] > 0 ? l[u] = findSet(l[u]) : u; }

void makeSet(int s, int t)
{
    if (l[s] < l[t]) swap(s, t);
    l[s] += l[t];
    l[t] = s;
}

ll calc()
{
    ll ret = 0;
    memset(l, -1, sizeof l);
    for (int i = 1; i < n; ++i)
    {
        int s = findSet(e[i].u), t = findSet(e[i].v);
        ret += ll(l[s]) * l[t] * e[i].w;
        makeSet(s, t);
    }
    return ret;
}

void solve()
{
    for (int i = 1; i < n; ++i)
        e[i].w = max(a[e[i].u], a[e[i].v]);
    sort(e + 1, e + n, [](TEdge x, TEdge y) { return x.w < y.w; });
    ans += calc();
    for (int i = 1; i < n; ++i)
        e[i].w = min(a[e[i].u], a[e[i].v]);
    sort(e + 1, e + n, [](TEdge x, TEdge y) { return x.w > y.w; });
    ans -= calc();
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i)
        scanf("%d%d", &e[i].u, &e[i].v);
    solve();
    printf("%lld\n", ans);
    return 0;
}
