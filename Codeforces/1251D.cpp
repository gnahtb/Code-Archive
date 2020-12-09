#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using ll = long long;

const int N = 2e5 + 2;

int t;
int n;
ll s, a[N];
pair<ll, ll> seg[N];
vector<ll> vs;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 1; i <= n; ++i) {
            cin >> seg[i].fi >> seg[i].se;
            a[i] = seg[i].fi;
            s -= a[i];
        }
        ll l = 0, r = 1e9, t;
        while (l <= r) {
            ll m = (l + r) / 2;
            int cnt = 0;
            for (int i = 1; i <= n; ++i)
                if (a[i] > m) ++cnt;
            if (cnt <= n / 2) {
                t = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        l = t; r = 1e9;
        ll ans;
        while (l <= r) {
            ll m = (l + r) / 2;
            vs.clear();
            int cs = 0;
            for (int i = 1; i <= n; ++i)
                if (a[i] < m) {
                    ++cs;
                    if (seg[i].se >= m)
                        vs.push_back(m - seg[i].fi);
                }
            sort(vs.begin(), vs.end());
            cs -= n / 2;
            ll sum = 0;
            bool ok = true;
            if (cs > 0) {
                if (cs > vs.size()) ok = false;
                else {
                    for (int i = 0; i < cs; ++i)
                        sum += vs[i];
                }
            }
            if (sum > s) ok = false;
            if (ok) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
