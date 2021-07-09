#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 2;

int test, n;
ll c, a[N], b[N], days[N];

int main() {
    cin >> test;
    while (test--) {
        cin >> n >> c;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i < n; ++i) cin >> b[i];
        ll rem = 0;
        ll ans = LLONG_MAX;
        days[0] = 0;
        for (int i = 1; i <= n; ++i) {
            // try to buy
            ll tmpc = max(1LL * c - rem, 0LL);
            ll da = (tmpc + a[i] - 1) / a[i];
            ans = min(ans, da + days[i - 1]);
            if (i == n) continue;
            // promotion
            ll tmp = max(1LL * b[i] - rem, 0LL);
            days[i] = (tmp + a[i] - 1) / a[i];
            rem = rem + 1LL * days[i] * a[i] - b[i];
            ++days[i];
            days[i] += days[i - 1];
        }
        cout << ans << "\n";
    }
    return 0;
}