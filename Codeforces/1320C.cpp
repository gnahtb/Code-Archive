#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using ll = long long;

const int N = 1e6;
const ll oo = 2e18;

struct IT {
    struct Node {
        int lf, rg;
        ll vl, lz;

        Node() { vl = lz = 0; }
    } a[N * 4 + 5];

#define md ((l + r) >> 1)
#define nx (i << 1)
    void Build(int l, int r, int i = 1) {
        a[i].lf = l;
        a[i].rg = r;
        if (l == r) return;
        Build(l, md, nx);
        Build(md + 1, r, nx + 1);
    }

    void Lazy(int i) {
        a[i].vl += a[i].lz;
        if (a[i].lf < a[i].rg) {
            a[nx].lz += a[i].lz;
            a[nx + 1].lz += a[i].lz;
        }
        a[i].lz = 0;
    }

    void Inc(int l, int r, ll x, int i = 1) {
        Lazy(i);
        if (a[i].lf > r || a[i].rg < l) return;
        if (l <= a[i].lf && a[i].rg <= r) {
            a[i].lz += x;
            Lazy(i);
            return;
        }
        Inc(l, r, x, nx);
        Inc(l, r, x, nx + 1);
        a[i].vl = max(a[nx].vl, a[nx + 1].vl);
    }

    ll Get(int l, int r, int i = 1) {
        Lazy(i);
        if (a[i].lf > r || a[i].rg < l) return -oo;
        if (l <= a[i].lf && a[i].rg <= r) return a[i].vl;
        ll ret = max(Get(l, r, nx), Get(l, r, nx + 1));
        return ret;
    }
#undef md
#undef nx
} it;

int n, m, p;
pair<int, int> att[N], def[N];
pair<pair<int, int>, int> mon[N];
ll ans = -oo;

istream& operator>>(istream& in, pair<int, int>& p) {
    in >> p.fi >> p.se;
    return in;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) cin >> att[i];
    for (int i = 1; i <= m; ++i) cin >> def[i];
    for (int i = 1; i <= p; ++i) cin >> mon[i].fi >> mon[i].se;
    sort(att + 1, att + n + 1);
    sort(def + 1, def + m + 1);
    sort(mon + 1, mon + p + 1);
    it.Build(1, N);
    ll curmin = oo;
    for (int i = N, j = m; i; --i) {
        while (j > 0 && def[j].fi > i) {
            curmin = min(curmin, (ll)def[j].se);
            --j;
        }
        it.Inc(i, i, -curmin);
    }
    ans = -att[1].se - def[1].se;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j <= p && mon[j].fi.fi < att[i].fi) {
            int idx = mon[j].fi.se;
            it.Inc(idx, N, mon[j].se);
            ++j;
        }
        ll tmp = it.Get(1, N);
        tmp -= att[i].se;
        ans = max(ans, tmp);
    }
    cout << ans << "\n";
    return 0;
}
