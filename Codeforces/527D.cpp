#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int maxN = 2E5 + 5;

int n, f[maxN];
vector<pii> a;

int search(int x)
{
    int l = 0, r = a.size() - 1, p = -1;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (a[m].fi <= x) p = m, l = m + 1;
        else r = m - 1;
    }
    return p;
}

void solve()
{
    memset(f, 0, sizeof f);
    for (int i = 0; i < n; ++i)
    {
        int p = search(a[i].se);
        if (p >= 0) f[i] = f[p] + 1;
        else f[i] = 1;
        f[i] = max(f[i - 1], f[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, w;
        cin >> x >> w;
        a.push_back({x + w, x - w});
    }
    sort(a.begin(), a.end());
    solve();
    cout << f[n - 1];
    return 0;
}
