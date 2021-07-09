#include <bits/stdc++.h>

using namespace std;

#define sqr(a) ((a) * (a))

typedef long double ld;

struct TPoint { ld x, y; };

const int N = 1E5 + 5;
const ld eps = 1E-6;

int n;
ld ans;
TPoint a[N];

bool check(ld rad) {
    ld l = -1E7, r = 1E7;
    for (int i = 0; i < n; ++i) {
        ld tmp = (rad + rad - a[i].y) * a[i].y;
        if (tmp < 0) return false;
        ld x0 = a[i].x - sqrt(tmp), x1 = a[i].x + sqrt(tmp);
        if (r < x0 || l > x1) return false;
        l = max(l, x0); r = min(r, x1);
    }
    return true;
}

void solve() {
    ld l = eps, r = 1E18;
    for (int i = 0; i < 100; ++i) {
        ld m = (l + r) / 2.0;
        if (check(m)) ans = r = m; else l = m;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    (cout << fixed).precision(10);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    for (int i = 1; i < n; ++i)
        if (a[0].y * a[i].y < 0) return cout << "-1\n", 0;
    for (int i = 0; i < n; ++i) a[i].y = abs(a[i].y);
    solve();
    cout << ans << "\n";
    return 0;
}
