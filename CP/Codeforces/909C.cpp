#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int mod = 1E9 + 7;

int n, f[5005][5005], ans = 0;
char a[5005];

void solve()
{
    memset(f, 0, sizeof f);
    f[0][1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j > 0; --j)
            if (a[i - 1] == 'f') f[i][j] = f[i - 1][j - 1];
            else f[i][j] = (f[i - 1][j] + f[i][j + 1]) % mod;
    for (int j = 1; j <= n; ++j) (ans += f[n][j]) %= mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    solve();
    cout << ans << "\n";
    return 0;
}
