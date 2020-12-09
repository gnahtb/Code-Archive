#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

template <typename T> void maximize(T &a, T b) { if (a < b) a = b; }

const int maxN = 305;

int n, a[maxN][maxN], f[2][maxN][maxN];

void solve()
{
    for (int i = 1; i <= n; ++i)
        fill(f[0][i] + 1, f[0][i] + n + 1, INT_MIN);
    f[0][1][1] = a[1][1];
    for (int d = 2; d < n + n; ++d)
    {
        for (int i = 1; i <= n; ++i)
            fill(f[(d + 1) & 1][i] + 1, f[(d + 1) & 1][i] + n + 1, INT_MIN);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) if (f[d & 1][i][j] > INT_MIN)
                for (int ni = i; ni < i + 2; ++ni) if (ni <= n && d - ni + 1 <= n)
                    for (int nj = j; nj < j + 2; ++nj) if (nj <= n && d - nj + 1 <= n)
                    {
                        int t = f[d & 1][i][j] + a[ni][d - ni + 1];
                        if (ni != nj) t += a[nj][d - nj + 1];
                        maximize(f[(d + 1) & 1][ni][nj], t);
                    }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
    solve();
    printf("%d\n", f[0][n][n]);
    return 0;
}
