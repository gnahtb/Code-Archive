#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll sod(ll x) {
    ll s = 0;
    while (x > 0) s += x % 10, x /= 10;
    return s;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        ll x;
        cin >> x;
        while (true) {
            ll g = __gcd(x, sod(x));
            if (g > 1) {
                cout << x << "\n";
                break;
            }
            ++x;
        }
    }
    return 0;
}