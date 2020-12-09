#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define long long long
#define fill(a, b) memset(a, b, sizeof a);

long n, h, ans = 0, f[40][40];

void solve()
{
    fill(f, 0);
    f[0][0] = 1;
    f[1][1] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int root = 1; root <= j; ++root)
            {
                long s1 = 0, s2 = 0, l = root - 1, r = j - root;
                for (int p = 0; p < i - 1; ++p)
                    s1 += f[p][l], s2 += f[p][r];
                f[i][j] += f[i - 1][l] * s2 + s1 * f[i - 1][r] + f[i - 1][l] * f[i - 1][r];
            }
    for (int i = h; i <= n; ++i) ans += f[i][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> h;
    solve();
    cout << ans;
    return 0;
}
