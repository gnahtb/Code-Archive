#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

#define fi first
#define se second

typedef pair<double, double> dd;

const int maxN = 2E5 + 5;
const double eps = 1E-9;

int n, T;
double ans = 0;
dd a[maxN];

void solve()
{
    double cur1 = 0, cur2 = 0;
    int L = 1, R = n;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].fi < 0) cur1 -= a[i].fi * a[i].se;
        if (a[i].fi > 0) cur2 += a[i].fi * a[i].se;
    }
    if (abs(cur1 - cur2) > eps)
    {
        while (L <= n && a[L].fi < 0 && cur1 - cur2 > eps)
        {
            double x = min((cur1 - cur2) / -a[L].fi, a[L].se);
            cur1 += a[L].fi * a[L].se;
            a[L].se -= x;
            cur1 -= a[L].fi * a[L].se; ++L;
        }
        while (R > 0 && a[R].fi > 0 && cur2 - cur1 > eps)
        {
            double x = min((cur2 - cur1) / a[R].fi, a[R].se);
            cur2 -= a[R].fi * a[R].se;
            a[R].se -= x;
            cur2 += a[R].fi * a[R].se; --R;
        }
    }
    for (int i = 1; i <= n; ++i) ans += a[i].se;
}

int main()
{
    ios_base::sync_with_stdio(false);
    (cout << fixed).precision(10);
    cin >> n >> T;
    for (int i = 1; i <= n; ++i) cin >> a[i].se;
    for (int i = 1; i <= n; ++i) cin >> a[i].fi, a[i].fi -= T;
    sort(a + 1, a + n + 1);
    solve();
    cout << ans << "\n";
    return 0;
}
