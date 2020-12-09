#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c;

// ax + by = g = gcd(a, b)
void extendedEuclidean(ll a, ll b, ll& r, ll& x, ll& y) {
    ll tx, ty, tr;
    x = 0; tx = 1;
    y = 1; ty = 0;
    r = b; tr = a;

    while (r != 0) {
        ll q = tr / r;
        ll tmp = tr;
        tr = r;
        r = tmp - q * r;

        tmp = tx;
        tx = x;
        x = tmp - q * x;

        tmp = ty;
        ty = y;
        y = tmp - q * y;
    }

    x = tx;
    y = ty;
    r = tr;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> a >> b >> c;

    ll g, x, y;
    extendedEuclidean(a, b, g, x, y);

    if (c % g != 0) {
        cout << "-1\n";
        return 0;
    }

    x *= c / g;
    y *= c / g;

    if (a * (-x) + b * y == -c)
        cout << (-x) << " " << y << "\n";
    else if (a * x + b * (-y) == -c)
        cout << x << " " << (-y) << "\n";
    else if (a * x + b * y == -c)
        cout << x << " " << y << "\n";
    else if (a * x + b * y == c)
        cout << (-x) << " " << (-y) << "\n";

    return 0;
}
