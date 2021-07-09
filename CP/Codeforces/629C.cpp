#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const int mod = 1E9 + 7;

int n, m, u = 0, l = 0, f[5000][5000];
ll ans = 0;
string s;

void solve()
{
    for (char c: s) u += ((c == '(') ? 1 : -1), l = min(l, u);
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int len = 1; len <= n - m; ++len)
        for (int i = 0; i <= n - m; ++i)
        {
            f[len][i] = f[len - 1][i + 1];
            if (i > 0) f[len][i] = (f[len][i] + f[len - 1][i - 1]) % mod;
        }
    for (int len = 0; len <= n - m; ++len)
        for (int i = 0; i <= n - m; ++i) if (i + l >= 0 && i + u <= n - m)
            ans = (ans + ll(f[len][i]) * ll(f[n - m - len][i + u]) % mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s;
    solve();
    cout << ans << "\n";
    return 0;
}
