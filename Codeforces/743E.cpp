#include <bits/stdc++.h>

using namespace std;

#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

template<typename T> void maximize(T &a, T b) { if (a < b) a = b; }
template<typename T> void minimize(T &a, T b) { if (a > b) a = b; }

const int maxN = 1005;
const int inf = 1000000007;

int n, a[maxN], u[maxN][maxN][8], f[256][10], ans = 0;

int getBit(int m, int i) { return m >> i & 1; }

void solve()
{
    FOR(i, 1, n)
    {
        int c[8];
        fill(c, c + 8, 0);
        FOR(j, 1, n) fill(u[i][j], u[i][j] + 8, inf);
        FOR(j, i, n) u[i][++c[a[j]]][a[j]] = j;
    }
    FOR(x, 0, n >> 3)
    {
        FOR(m, 0, 255) fill(f[m], f[m] + 10, inf);
        f[0][0] = 1;
        FOR(m, 0, 255) FOR(i, 0, 8) if (f[m][i] <= n)
            FOR(j, 0, 7) if (!getBit(m, j))
            {
                minimize(f[m | 1 << j][i], u[f[m][i]][x][j] + 1);
                minimize(f[m | 1 << j][i + 1], u[f[m][i]][x + 1][j] + 1);
            }
        FOR(i, 0, 8) if (f[255][i] <= n + 1)
            maximize(ans, x * (8 - i) + (x + 1) * i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    FOR(i, 1, n) cin >> a[i], --a[i];
    solve();
    cout << ans << "\n";
    return 0;
}
