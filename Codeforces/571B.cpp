#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define minimize(a, b) a = min(a, b)

typedef long long ll;

const int maxN = 3E5 + 5;

int n, k;
ll a[maxN], s[maxN], f[5005][5005];

void prep()
{
    memset(s, 0, sizeof s);
    for (int i = 1; i <= n; ++i)
        s[i] = a[i] - a[i - 1], s[i] += s[i - 1];
}

void solve()
{
    memset(f, 0, sizeof f);
    int n1 = n % k, n0 = k - n1;
    for (int i = 0; i <= n0; ++i)
        for (int j = 0; j <= n1; ++j)
        {
            if (i + j < 1) continue;
            f[i][j] = LLONG_MAX;
            int u = n / k * (i + j) + j;
            if (i > 0) minimize(f[i][j], f[i - 1][j] + s[u] - s[u - n / k + 1]);
            if (j > 0) minimize(f[i][j], f[i][j - 1] + s[u] - s[u - n / k]);
        }
    printf("%lld\n", f[n0][n1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    prep();
    solve();
    return 0;
}
