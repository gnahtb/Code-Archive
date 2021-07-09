#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1E9 + 7;
const int maxN = 505;

int n;
ll f[maxN][maxN], g[maxN][maxN], h[maxN][maxN];
bool e[maxN][maxN];

void solve()
{
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    for (int i = 1; i <= n; ++i)
    {
        f[i][i] = h[i][i] = 1;
        f[i][i + 1] = h[i][i + 1] = e[i][i + 1];
    }
    for (int d = 2; d < n; ++d)
        for (int L = 1, R = L + d; R <= n; ++L, ++R)
        {
            for (int i = L + 1; i < R; ++i)
                (g[L][R] += f[L][i] * h[i][R] % mod) %= mod;
            for (int i = L; i < R; ++i)
                (f[L][R] += e[L][R] * h[L][i] * h[i + 1][R] % mod) %= mod;
            h[L][R] = (f[L][R] + g[L][R]) % mod;
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cin >> e[i][j];
    solve();
    cout << h[1][n];
    return 0;
}
