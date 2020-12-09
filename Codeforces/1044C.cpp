#include <bits/stdc++.h>

#define sz(a) (int)a.size()
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

const int N = 3e5 + 2;
const int oo = 1e9;

struct IT {
    struct Node {
        int lf, rg;
        vector<int> vt;
    } a[N << 2];

#define nx (i << 1)
#define md ((l + r) >> 1)
    void build(int l, int r, int i = 1) {
        a[i].lf = l;
        a[i].rg = r;
        a[i].vt.clear();
        if (l == r) return;
        build(l, md, nx);
        build(md + 1, r, nx + 1);
    }

    void upd(int p, int x, int i = 1) {
        if (a[i].lf > p || a[i].rg < p) return;
        a[i].vt.push_back(x);
        if (a[i].lf == p && p == a[i].rg) return;
        upd(p, x, nx);
        upd(p, x, nx + 1);
    }

    void mod(int i = 1) {
        sort(a[i].vt.begin(), a[i].vt.end());
        if (a[i].lf == a[i].rg) return;
        mod(nx);
        mod(nx + 1);
    }

    int getu(int l, int r, int x, int i = 1) {
        if (a[i].lf > r || a[i].rg < l) return 0;
        if (l <= a[i].lf && a[i].rg <= r) {
            int ret = a[i].vt.end() - lower_bound(a[i].vt.begin(), a[i].vt.end(), x);
            return ret;
        }
        return getu(l, r, x, nx) + getu(l, r, x, nx + 1);
    }

    int getd(int l, int r, int x, int i = 1) {
        if (a[i].lf > r || a[i].rg < l) return 0;
        if (l <= a[i].lf && a[i].rg <= r) {
            int ret = upper_bound(a[i].vt.begin(), a[i].vt.end(), x) - a[i].vt.begin();
            return ret;
        }
        return getd(l, r, x, nx) + getd(l, r, x, nx + 1);
    }
#undef nx
#undef md
} itcnt;

struct IT1 {
    struct Node {
        int lf, rg, mx = -oo, mn = oo;
    } a[N << 2];

#define nx (i << 1)
#define md ((l + r) >> 1)
    void build(int l, int r, int i = 1) {
        a[i].lf = l;
        a[i].rg = r;
        if (l == r) return;
        build(l, md, nx);
        build(md + 1, r, nx + 1);
    }

    void upd(int p, int x, int i = 1) {
        if (a[i].lf > p || a[i].rg < p) return;
        if (p == a[i].lf && a[i].rg == p) {
            a[i].mx = max(a[i].mx, x);
            a[i].mn = min(a[i].mn, x);
            return;
        }
        upd(p, x, nx);
        upd(p, x, nx + 1);
        a[i].mx = max(a[nx].mx, a[nx + 1].mx);
        a[i].mn = min(a[nx].mn, a[nx + 1].mn);
    }

    int getmx(int l, int r, int i = 1) {
        if (a[i].lf > r || a[i].rg < l) return -oo;
        if (l <= a[i].lf && a[i].rg <= r) {
            return a[i].mx;
        }
        return max(getmx(l, r, nx), getmx(l, r, nx + 1));
    }

    int getmn(int l, int r, int i = 1) {
        if (a[i].lf > r || a[i].rg < l) return oo;
        if (l <= a[i].lf && a[i].rg <= r) {
            return a[i].mn;
        }
        return min(getmn(l, r, nx), getmn(l, r, nx + 1));
    }
#undef nx
#undef md
} itx, ity;

int n, mxx = -oo, mxy = -oo, mnx = oo, mny = oo;
pii a[N];
vector<int> lx, ly;

int get_id(int x, vector<int>& v) {
    return (lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
        lx.push_back(a[i].fi);
        ly.push_back(a[i].se);
        mxx = max(mxx, a[i].fi);
        mxy = max(mxy, a[i].se);
        mnx = min(mnx, a[i].fi);
        mny = min(mny, a[i].se);
    }
    sort(lx.begin(), lx.end());
    lx.erase(unique(lx.begin(), lx.end()), lx.end());
    sort(ly.begin(), ly.end());
    ly.erase(unique(ly.begin(), ly.end()), ly.end());
    itcnt.build(1, sz(lx));
    itx.build(1, sz(lx));
    ity.build(1, sz(ly));
    for (int i = 1; i <= n; ++i) {
        itcnt.upd(get_id(a[i].fi, lx), a[i].se);
        itx.upd(get_id(a[i].fi, lx), a[i].se);
        ity.upd(get_id(a[i].se, ly), a[i].fi);
    }
    itcnt.mod();
    int ans = -oo;
    for (int i = 1; i <= n; ++i) {
        int px = get_id(a[i].fi, lx);
        int py = get_id(a[i].se, ly);

        // up left
        int tmp = itcnt.getu(1, px, a[i].se);
        if (tmp > 2) {
            int t1 = itx.getmx(1, px);
            int t2 = ity.getmn(py, sz(ly));
            ans = max(ans, (t1 + a[i].fi - a[i].se - t2));
        }

        // up right
        tmp = itcnt.getu(px, sz(lx), a[i].se);
        if (tmp > 2) {
            int t1 = itx.getmx(px, sz(lx));
            int t2 = ity.getmx(py, sz(ly));
            ans = max(ans, (t1  + t2 - a[i].fi - a[i].se));
        }

        // down left
        tmp = itcnt.getd(1, px, a[i].se);
        if (tmp > 2) {
            int t1 = itx.getmn(1, px);
            int t2 = ity.getmn(1, py);
            ans = max(ans, (a[i].fi + a[i].se - t1 - t2));
        }

        // down right
        tmp = itcnt.getd(px, sz(lx), a[i].se);
        if (tmp > 2) {
            int t1 = itx.getmn(px, sz(lx));
            int t2 = ity.getmx(1, py);
            ans = max(ans, (t2 - a[i].fi + a[i].se - t1));
        }
    }
    cout << (ans * 2) << " ";
    for (int i = 4; i <= n; ++i) {
        cout << ((mxx + mxy - mnx - mny) * 2) << " ";
    }
    return 0;
}
