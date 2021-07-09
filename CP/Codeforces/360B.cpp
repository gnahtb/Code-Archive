#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2002;
const int oo = 2e9;

int n, k, a[N];
ll f[N][2];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll l = 0, r = oo, ans = oo;
    while (l <= r) {
        ll m = (l + r) / 2;
        fill(f[0], f[N], oo);
        f[0][0] = f[0][1] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i][0] = min(f[i - 1][0], f[i - 1][1]) + 1;
            f[i][1] = i - 1;
            for (int j = 1; j < i; ++j) {
                int tmp = i - j;
                int tmp1 = abs(a[i] - a[j]) / tmp + (abs(a[i] - a[j]) % tmp > 0);
                if (tmp1 <= m) {
                    f[i][1] = min(f[i][1], f[j][1] + tmp - 1);
                }
            }
        }
        ll opers = min(f[n][0], f[n][1]);
        if (opers <= k) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
