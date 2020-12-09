#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int inf = 2147483647;

int n, k, p, a[1005], b[2005], f[1005][2005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> p;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= k; ++i) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; ++i)
    {
        f[i][0] = inf;
        for (int j = 1; j <= k; ++j)
        {
            int t = max(f[i - 1][j - 1], abs(a[i] - b[j]) + abs(b[j] - p));
            f[i][j] = min(t, f[i][j - 1]);
        }
    }
    cout << f[n][k];
    return 0;
}
