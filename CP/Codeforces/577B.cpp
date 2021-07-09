#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, m, a[2000];
bool f[2000][2000];

void solve()
{
    memset(f, false, sizeof f);
    f[1][a[1]] = true;
    for (int i = 2; i <= n; ++i)
    {
        f[i][a[i]] = true;
        for (int j = 0; j < m; ++j)
            f[i][j] = f[i][j] || f[i - 1][j] || f[i - 1][(j - a[i] + m) % m];
    }
    f[n][0] ? cout << "YES" : cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if (n >= m) { cout << "YES"; return 0; }
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] = a[i] % m;
    solve();
    return 0;
}
