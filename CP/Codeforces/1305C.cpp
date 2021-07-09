#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll Pow(ll x, ll y, ll z) {
    if (y == 0) return 1 % z;
    ll t = Pow(x, y >> 1, z);
    (t *= t) %= z;
    if ((y & 1) != 0) (t *= x) %= z;
    return t;
}

const int N = 2e5 + 2;

int n, m, a[N];
map<int, ll> cnt, cnt1;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (cnt[a[i] % m] > 0) {
            cout << "0\n";
            return 0;
        }
        for (int j = 1; j < m; ++j) {
            int expe = ((a[i] - j) % m + m) % m;
            cnt1[j] += cnt[expe];
        }
        ++cnt[a[i] % m];
    }
    ll ans = 1;
    for (int i = 1; i < m; ++i) {
        (ans *= Pow(i, cnt1[i], m)) %= m;
    }
    cout << ans << "\n";
    return 0;
}
