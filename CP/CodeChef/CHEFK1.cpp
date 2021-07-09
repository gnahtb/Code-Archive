#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
ll n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (m < n - 1 || m > n + n * (n - 1) / 2) {
            cout << "-1\n";
            continue;
        }
        if (n == 1) {
            cout << (m == 1 ? 1 : 0) << "\n";
            continue;
        }
        ll m1 = m - n + 1;
        if (m1 >= n) {
            ll t = (m - n) * 2 / n;
            ll t1 = (m - n) * 2 % n;
            cout << (1 + t + (t1 > 0)) << "\n";
            continue;
        }
        if (n == 2 && m1 < 1) {
            cout << "1\n";
            continue;
        }
        cout << (m1 < 3 ? 2 : 3) << "\n";
    }
    return 0;
}