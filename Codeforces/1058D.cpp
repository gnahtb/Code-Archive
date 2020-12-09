#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, k;
vector<ll> dv;

int main() {
    cin >> n >> m >> k;
    ll g = __gcd(n * m, k);
    if (k / g > 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    ll c = k / g == 2 ? 1 : 2;
    for (ll i = 1; i * i <= g; ++i)
        if (g % i == 0) {
            dv.push_back(i);
            if (i * i < g) dv.push_back(g / i);
        }
    for (int i = 0; i < (int)dv.size(); ++i) {
        if (n % dv[i] == 0 && m % (g / dv[i]) == 0) {
            ll n1 = n / dv[i];
            ll m1 = m / (g / dv[i]);
            if (n1 * c <= n && m1 <= m) {
                cout << "0 0\n";
                cout << (n1 * c) << " 0\n";
                cout << "0 " << m1 << "\n";
                return 0;
            }
            if (n1 <= n && m1 * c <= m) {
                cout << "0 0\n";
                cout << n1 << " 0\n";
                cout << "0 " << (m1 * c) << "\n";
                return 0;
            }
        }
    }
    return 0;
}
