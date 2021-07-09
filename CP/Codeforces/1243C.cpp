#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, ans;
vector<ll> dv;

int main() {
    cin >> n;
    // ll tn = n;
    int cnte = 0;
    while (n % 2 == 0) {
        ++cnte;
        n /= 2;
    }
    if (n > 1) {
        // cout << "1\n";
        if (cnte > 0) {
            cout << "1\n";
            return 0;
        }
        ans = n;
        // ll x = -1;
        for (ll i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                dv.push_back(i);
                if (i * i < n) dv.push_back(n / i);
            }
        }
        if (dv.size() > 0) ans = dv.front();
        for (int i = 1; i < dv.size(); ++i)
            if (dv[i] % dv.front() != 0) {
                ans = 1;
                break;
            }
        cout << ans << "\n";
        return 0;
    }
    if (n == 1 && cnte == 0) cout << "1\n";
    else cout << "2\n";
    return 0;
}
