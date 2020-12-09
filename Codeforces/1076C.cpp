#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld eps = 1E-10;

int t;

int main() {
    ios_base::sync_with_stdio(false);
    (cout << fixed).precision(10);
    cin >> t;
    while (t--) {
        ld n, d = -1;
        cin >> n;
        if (n == 0.0) {
            cout << "Y 0 0\n";
            continue;
        }
        if (n == 4.0) {
            cout << "Y 2 2\n";
            continue;
        }
        ld l = 0, r = n;
        for (int i = 1; i <= 1000; ++i) {
            ld mid = (l + r) / 2.0;
            ld a = (n + mid) / 2.0, b = (n - mid) / 2.0;
            ld p = a * b;
            if (abs(p - n) <= eps) {
                d = mid;
                break;
            } else if (p - n < -eps) r = mid;
            else l = mid;
        }
        if (d >= 0)
            cout << "Y " << (n + d) / 2.0 << " " << (n - d) / 2.0 << "\n";
        else cout << "N\n";
    }
    return 0;
}
