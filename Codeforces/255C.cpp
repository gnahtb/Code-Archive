#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define init(a, b) memset(a, b, sizeof(a))

int n, ans = 1, b[4005], p[1000005], f[4005][4005];

void solve()
{
    init(f, 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j) p[b[j]] = 0;
        for (int j = 1; j < i; ++j)
        {
            if (p[b[i]] > 0) f[i][j] = f[j][p[b[i]]] + 1;
            else f[i][j] = 2;
            ans = max(ans, f[i][j]);
            p[b[j]] = j;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    solve();
    cout << ans;
    return 0;
}
