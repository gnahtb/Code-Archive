#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define long long long
#define sqr(a) (a) * (a)

const int maxN = 1E5 + 5;
const long mod = 1E9 + 7;

int n, a[maxN];
long ans = 0;

long power(long x, long y)
{
    if (!y) return 1;
    long r = power(x, y >> 1LL);
    (r *= r) %= mod;
    if ((y & 1)) (r *= x) %= mod;
    return r;
}

int search(int param)
{
    int L = 1, R = n + 1, p = -1;
    while (L <= R)
    {
        int mid = (L + R) >> 1;
        if (a[mid] >= param) p = mid, R = mid - 1;
        else L = mid + 1;
    }
    return p;
}

void solve()
{
    a[n + 1] = INT_MAX;
    for (int i = 1; i <= a[n]; ++i)
    {
        vector<int> d;
        long pd = 1, pf = 0, cur = -1;
        for (int j = 1; sqr(j) <= i; ++j)
            if (!(i % j)) d.push_back(j), d.push_back(i / j);
        sort(d.begin(), d.end());
        d.resize(distance(d.begin(), unique(d.begin(), d.end())));
        for (int j = 0; j < (int)d.size(); ++j)
        {
            int k = search(d[j]);
            if (j) (pd *= power(power(j, n - k + 1), mod - 2)) %= mod;
            (pd *= power(j + 1, n - k + 1)) %= mod;
            cur = (pd - pf + mod) % mod;
            (pf += cur) %= mod;
        }
        (ans += cur) %= mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    solve();
    printf("%lld\n", ans);
    return 0;
}
