#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, p, w, d;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> p >> w >> d;
    ll r = p % (w + d);
    for (ll y = 0; y < w + d; ++y) {
        if (w * y % (w + d) == r && w * y <= p) {
            ll t = (p - w * y) / (w + d);
            ll rg = (n - y - t) / d;
            ll rg1 = t / w;
            ll t1 = min(rg, rg1);
            ll t2 = t - t1 * w;
            if (t2 + t2 + y + (w + d) * t1 <= n)  {
                cout << (t2 + y + (w + d) * t1) << " " << t2 << " " << (n - (t2 + t2 + y + (w + d) * t1)) << "\n";
                return 0;
            }
        }
        if (d * y % (w + d) == r && d * y <= p) {
            ll t = (p - d * y) / (w + d);
            if (t + t + y <= n) {
                cout << t << " " << (y + t) << " " << (n - y - t - t) << "\n";
                return 0;
            }
        }
    }
    cout << "-1\n";
    return 0;
}
