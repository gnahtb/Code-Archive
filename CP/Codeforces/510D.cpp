#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define fi first
#define se second
#define sqr(a) (a) * (a)

typedef pair<int, int> pii;

const int maxN = 305;

int n, l[maxN], c[maxN];
vector<pii> e;
vector<int> visited;
priority_queue<pii, vector<pii>, greater<pii>> q;

int shorten(int param)
{
    int p = 1;
    while (param > 1)
    {
        int d = param;
        for (int i = 2; sqr(i) <= param; ++i) if (param % i == 0) { d = i; break; }
        while (param % d == 0) param /= d;
        p *= d;
    }
    return p;
}

void dijkstra()
{
    for (pii p: e) q.push(p);
    while (!q.empty())
    {
        while (binary_search(visited.begin(), visited.end(), q.top().se)) q.pop();
        int d = q.top().fi, u = q.top().se;
        if (u == 1) break;
        visited.push_back(u); sort(visited.begin(), visited.end());
        for (pii p: e)
        {
            int v = __gcd(u, p.se);
            if (!binary_search(visited.begin(), visited.end(), v)) q.push({d + p.fi, v});
        }
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    int t = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &l[i]);
        (t == 0) ? t = l[i] : t = __gcd(t, l[i]);
    }
    if (t > 1) { printf("-1\n"); return 0; }
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    for (int i = 0; i < n; ++i) e.push_back({c[i], shorten(l[i])});
    dijkstra();
    printf("%d\n", q.top().fi);
    return 0;
}
