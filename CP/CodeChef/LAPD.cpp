#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int t;
ll a, b, c;

int main() {
    cin >> t;
    while (t--) {
        ll ans = 0;
        cin >> a >> b >> c;
        for (int j = 1; j <= b; ++j) {
            ll tmp = ((a - 1) * (c - 1) % MOD + min(a - 1, (ll)j) * min(c - 1, (ll)j) % MOD) % MOD;
            for (int k = 1; k <= j; ++k) {
                ll tmp1 = j * j / k;
                if (k < a) (tmp += MOD - min(c - 1, tmp1)) %= MOD;
                if (k < c) (tmp += MOD - min(a - 1, tmp1)) %= MOD;
            }
            // cout << j << " " << tmp << "\n";
            (ans += tmp) %= MOD;
        }
        cout << ans << "\n";
    }
}