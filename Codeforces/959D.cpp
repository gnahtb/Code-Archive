#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define sqr(a) (a) * (a)

const int limit = 2E6 + 5;
const int maxN = 1E5 + 5;

int p[limit], n, a[maxN], z;
bool avail[limit];

void sieve()
{
    memset(p, 0, sizeof p);
    for (int i = 2; i < limit; ++i) p[i] = i;
    for (int i = 2; sqr(i) < limit; ++i) if (p[i] == i)
        for (int j = sqr(i); j < limit; j += i) p[j] = i;
}

vector<int> fact(int x)
{
    vector<int> d;
    while (x > 1)
    {
        int t = p[x];
        while (x % t == 0) x /= t;
        d.push_back(t);
    }
    return d;
}

bool check(int x)
{
    vector<int> d = fact(x);
    for (int v: d) if (!avail[v]) return false;
    for (int v: d) avail[v] = false;
    return true;
}

int findPos()
{
    memset(avail, true, sizeof avail);
    for (int i = 0; i < n; ++i) if (!check(a[i])) return i;
    return n;
}

void solve()
{
    for (int v = a[z] + 1; v < limit; ++v)
    {
        if (!check(v)) continue;
        a[z] = v; break;
    }
    int v = 2;
    for (int i = z + 1; i < n; ++i)
    {
        while (!check(v)) ++v;
        a[i] = v;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sieve();
    z = findPos();
    if (z < n) solve();
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    return 0;
}
