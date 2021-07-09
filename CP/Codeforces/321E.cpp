#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

template <typename T>
inline void read_int(T &var = 0) {
    T sign = 1;
    char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar())
        if (ch == '-') sign = -1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        (var *= 10) += ch - '0';
    var *= sign;
}

const int N_MAX = 4005, K_MAX = 805, INF = 1e9;

#define int int_fast32_t

int n, k, u[N_MAX][N_MAX], c[N_MAX][N_MAX], f[K_MAX][N_MAX];

void solve(int t, int l, int r, int il, int ir) {
    if (l > r) return;
    int x = (l + r) / 2, minp = -1;
    f[t][x] = INF;
    for (int i = il; i <= min(x, ir); ++i) {
        int tmp = f[t - 1][i - 1];
        if (tmp < 0) continue;
        tmp += c[i][x];
        if (tmp < f[t][x]) {
            minp = i;
            f[t][x] = tmp;
        }
    }
    solve(t, l, x - 1, il, minp);
    solve(t, x + 1, r, minp, ir);
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("inp.txt", "r", stdin);
    read_int(n);
    read_int(k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) read_int(u[i][j]);
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= n; ++i)
            u[i][j] += u[i - 1][j];
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            c[i][j] = c[i][j - 1] + u[j][j] - u[i - 1][j];
    memset(f, -1, sizeof f);
    f[0][0] = 0;
    for (int t = 1; t <= k; ++t)
        solve(t, 1, n, 1, n);
    cout << f[k][n] << "\n";
    return 0;
}
