#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;

int main() {
    cin >> n >> k;

    ll l = 0, r = 1e9;
    while (l <= r) {
        ll m = (l + r) / 2;
        ll t = m * (m + 3) / 2;
        if (t == n + k) {
            ll ans = m * (m + 1) / 2 - k;
            cout << ans << endl;
            return 0;
        } else if (t < n + k) l = m + 1;
        else r = m - 1;
    }

    return 0;
}
