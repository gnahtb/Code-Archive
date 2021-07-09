#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int LIM = 320;
const ll MOD = 1E9 + 7;

int n, m, x;
ll f[2][LIM][LIM];

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d%d%d", &n, &m, &x);
    if (n > m) return printf("0\n"), 0;
    f[0][0][0] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; j + k <= n; ++k) {
                f[i & 1][j][k] = 0;
                //open a new bracket
                if (k) (f[i & 1][j][k] += f[(i - 1) & 1][j][k - 1]) %= MOD;
                //close a previous open bracket
                if (i != x && j) (f[i & 1][j][k] += f[(i - 1) & 1][j - 1][k + 1]) %= MOD;
                //open and close immediately a pair of brackets
                if (j) (f[i & 1][j][k] += f[(i - 1) & 1][j - 1][k]) %= MOD;
                //do nothing
                if (i != x) (f[i & 1][j][k] += f[(i - 1) & 1][j][k]) %= MOD;
            }
    for (int i = 2; i <= n; ++i) (f[m & 1][n][0] *= (ll)i) %= MOD;
    printf("%lld\n", f[m & 1][n][0]);
    return 0;
}
