#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 12;
const ll oo = 1e18;

int n, m, k;
ll f[M], ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    ll cur = 0;
    fill(f + 1, f + m, oo);
    f[0] = k;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        cur += a;
        for (int j = 0; j < m; ++j) {
            ans = max(ans, cur - f[j]);
        }
        f[i % m] = min(f[i % m], cur) + k;
    }
    cout << ans << endl;
    return 0;
}
