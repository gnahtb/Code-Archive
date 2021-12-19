#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;

int test, n, k;
vector<ll> pos, neg;

int main() {
    cin >> test;
    while (test--) {
        cin >> n >> k;
        pos.clear();
        neg.clear();
        for (int i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            if (a > 0) pos.push_back(a);
            if (a < 0) neg.push_back(a);
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        ll ans = 0;
        for (int i = sz(pos) - 1; i >= 0; i -= k) ans += pos[i] * 2;
        for (int i = 0; i < sz(neg); i += k) ans += abs(neg[i]) * 2;
        ll t = 0;
        if (sz(pos) > 0) t = max(t, pos[sz(pos) - 1]);
        if (sz(neg) > 0) t = max(t, abs(neg[0]));
        ans -= t;
        cout << ans << endl;
    }
    return 0;
}