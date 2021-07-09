#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

#define fi first
#define se second
#define sz(a) (int)a.size()

const int maxN = 2E5 + 5;

int n, T, k = 0, p[maxN];
ii a[maxN];

bool check(int param)
{
    vector<int> u;
    int sum = 0;
    for (int i = 0; i < n; ++i)
        if (a[i].fi >= param) u.push_back(i);
    sort(u.begin(), u.end(), [](int x, int y) { return a[x].se < a[y].se; });
    if (sz(u) < param) return false;
    for (int i = 0; i < param; ++i) sum += a[u[i]].se;
    if (sum > T) return false;
    for (int i = 0; i < param; ++i) p[i] = u[i] + 1;
    return true;
}

void solve()
{
    int L = 1, R = n;
    while (L <= R)
    {
        int mid = (L + R) >> 1;
        if (check(mid)) k = mid, L = mid + 1;
        else R = mid - 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &T);
    for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].fi, &a[i].se);
    solve();
    printf("%d\n%d\n", k, k);
    for (int i = 0; i < k; ++i) printf("%d ", p[i]);
    return 0;
}
