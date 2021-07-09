#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct TData { int L, R, cost; };

const int limit = 2E5 + 5;

int n, x, ans = INT_MAX;
TData a[limit];
vector<int> u[limit], f[limit];

int search(int o, int param)
{
    int low = 0, high = u[o].size() - 1, pos = -1;
    while (low <= high)
    {
        int med = (low + high) >> 1;
        if (a[u[o][med]].L > param) pos = med, low = med + 1;
        else high = med - 1;
    }
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &a[i].L, &a[i].R, &a[i].cost);
        u[a[i].R - a[i].L + 1].push_back(i);
    }
    for (int d = 1; d < limit; ++d) if (u[d].size())
    {
        sort(u[d].begin(), u[d].end(), [](int p, int q) {
            if (a[p].L == a[q].L) return a[p].cost > a[q].cost;
            return a[p].L > a[q].L;
        });
        int tmp = INT_MAX;
        for (int i: u[d]) tmp = min(tmp, a[i].cost), f[d].push_back(tmp);
    }
    for (int d = 1; d < x; ++d) for (int i: u[d])
    {
        int k = search(x - d, a[i].R);
        if (k >= 0) ans = min(ans, a[i].cost + f[x - d][k]);
    }
    printf("%d\n", (ans < INT_MAX) ? ans : -1);
    return 0;
}
