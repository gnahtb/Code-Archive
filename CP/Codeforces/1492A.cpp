#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t;

int main() {
    cin >> t;
    while (t--) {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        ll ta = (p / a + (p % a > 0)) * a;
        ll tb = (p / b + (p % b > 0)) * b;
        ll tc = (p / c + (p % c > 0)) * c;
        cout << min(ta - p, min(tb - p, tc - p)) << "\n";
    }
    return 0;
}