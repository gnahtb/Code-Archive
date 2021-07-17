#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1002;
const ll oo = 1e16;

int n, m;
ll c, a[N][N], f[N][N], ans = oo;

int main() {
    fill(f[0], f[N], oo);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + c;
            ans = min(ans, f[i][j] + a[i][j]);
            f[i][j] = min(f[i][j], a[i][j]);
        }
    }
    fill(f[0], f[N], oo);
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j; --j) {
            f[i][j] = min(f[i - 1][j], f[i][j + 1]) + c;
            ans = min(ans, f[i][j] + a[i][j]);
            f[i][j] = min(f[i][j], a[i][j]);
        }
    }
    cout << ans;
    return 0;
}