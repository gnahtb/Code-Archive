#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 52;

int n;
ll a[N], b[N], ps[N], f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        ps[i] = ps[i - 1] + a[i] * b[i];
        f[i][i] = a[i] * b[i];
    }
    for (int d = 1; d < n; ++d) {
        for (int l = 1, r = d + 1; r <= n; ++l, ++r) {
            f[l][r] = f[l + 1][r - 1] + a[l] * b[r] + a[r] * b[l];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ll tmp = ps[i - 1] + ps[n] - ps[j] + f[i][j];
            ans = max(ans, tmp);
        }
    }
    cout << ans;
    return 0;
}