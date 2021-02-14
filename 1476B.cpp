#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 102;

int t, n, k;
ll a[N];

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> a[i];
        ll lf = 0, rg = 1e12, ans = -1;
        while (lf <= rg) {
            ll md = (lf + rg) / 2;
            ll current = a[0] + md;
            bool flag = true;
            for (int i = 1; i < n; ++i) {
                if (a[i] * 100 > current * k) {
                    flag = false;
                    break;
                }
                current += a[i];
            }
            if (flag) {
                ans = md;
                rg = md - 1;
            } else {
                lf = md + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}