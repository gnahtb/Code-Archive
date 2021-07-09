#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 2;

int n;
ll a[N], b[N], c[N], ans = LLONG_MAX;
vector<ll> p;

int main() {
    ios::sync_with_stdio(false);
    ll s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    while (s > 1) {
        ll t = s;
        for (ll i = 2; i * i <= s; ++i)
            if (s % i == 0) {
                t = i;
                break;
            }
        p.push_back(t);
        while (s % t == 0) s /= t;
    }
    for (ll x : p) {
        for (int i = 1; i <= n; ++i) b[i] = a[i] % x;
        bool flag = true;
        ll cur = 0;
        int l = 1;
        while (l <= n) {
            if (b[l] == 0) { ++l; continue; }
            int r = l - 1;
            ll need = b[l] + (x - b[l]) % x, sum = 0;
            while (r < n && sum < need) {
                ++r;
                c[r] = min(need - sum, b[r]);
                sum += c[r];
                b[r] -= c[r];
            }
            if (sum < need) {
                flag = false;
                break;
            }
            sum = 0;
            int y;
            for (y = l; y <= r; ++y) {
                sum += c[y];
                if (sum > (need + b[l]) / 2) break;
            }
            for (int i = l; i <= r; ++i) {
                cur += c[i] * abs(i - y);
            }
            l = r;
        }
        if (flag) {
            ans = min(ans, cur);
        }
    }
    if (ans == LLONG_MAX) ans = -1;
    cout << ans << "\n";
    return 0;
}
