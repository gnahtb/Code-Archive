#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;

struct TNode {
    int il = 0, ir = 0;
    ll ans = 0;
    vector<ii> vl, vr;
};

const int N = 1E5 + 5;

int n, m, x, a[N];
TNode st[N * 4];

template<typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> p) {
    out << "{" << p.first << ' ' << p.second << "}";
    return out;
}

TNode operator +(const TNode &lhs, const TNode &rhs) {
    TNode r;
    r.il = lhs.il;
    r.ir = rhs.ir;
    r.ans = lhs.ans + rhs.ans;
    if (!sz(lhs.vl) || !sz(rhs.vl)) {
        r.vl = sz(lhs.vl) ? lhs.vl : rhs.vl;
        r.vr = sz(lhs.vr) ? lhs.vr : rhs.vr;
        return r;
    }
    for (int i = 0, j = 0, k = lhs.il; i < sz(lhs.vr); k = lhs.vr[i++].se + 1) {
        while (j < sz(rhs.vl) && (lhs.vr[i].fi | rhs.vl[j].fi) < x) ++j;
        // cout << i << " " << j << "\n";
        if (j >= sz(rhs.vl)) break;
        // int t = (rhs.ir - rhs.vl[j].se + 1) * (lhs.vr[i].se - k + 1);
        r.ans += (ll)(rhs.ir - rhs.vl[j].se + 1) * (ll)(lhs.vr[i].se - k + 1);
        // cout << t << "\n";
    }
    for (int i = sz(lhs.vr) - 1, c = rhs.vr.front().fi; i >= 0; c |= lhs.vr[i--].fi)
        if ((c | lhs.vr[i].fi) > c)
            r.vr.push_back({c | lhs.vr[i].fi, lhs.vr[i].se});
    reverse(r.vr.begin(), r.vr.end());
    for (ii i : rhs.vr) r.vr.push_back(i);
    for (ii i : lhs.vl) r.vl.push_back(i);
    for (int i = 0, c = lhs.vl.back().fi; i < sz(rhs.vl); c |= rhs.vl[i++].fi)
        if ((c | rhs.vl[i].fi) > c)
            r.vl.push_back({c | rhs.vl[i].fi, rhs.vl[i].se});
    return r;
}

void build(int i, int l, int r) {   
    if (l == r) {
        st[i].il = l; st[i].ir = r;
        st[i].ans = a[l] >= x;
        st[i].vl.push_back({a[l], l}); st[i].vr.push_back({a[r], r});
        return;
    }
    build(i * 2, l, (l + r) / 2);
    build(i * 2 + 1, (l + r) / 2 + 1, r);
    st[i] = st[i * 2] + st[i * 2 + 1];
}

void update(int p, int i) {
    if (st[i].il == st[i].ir) {
        st[i].ans = a[p] >= x;
        st[i].vl[0].fi = a[p]; st[i].vr[0].fi = a[p];
        return;
    }
    update(p, i * 2 + ((st[i * 2].il <= p && p <= st[i * 2].ir) ^ 1));
    // build(i * 2, l, (l + r) / 2);
    // build(i * 2 + 1, (l + r) / 2 + 1, r);
    st[i] = st[i * 2] + st[i * 2 + 1];
}

TNode query(int i, int p, int q) {
    // cout << i << "\n";
    if (st[i].il > q || st[i].ir < p) {
        TNode r;
        r.il = max(p, st[i].il); r.ir = min(q, st[i].ir);
        return r;
    }
    if (p <= st[i].il && st[i].ir <= q) return st[i];
    return query(i * 2, p, q) + query(i * 2 + 1, p, q);
}

// int simque(int i, int p, int q) {
//     cout << st[i].il << " " << st[i].ir << "\n";
//     if (st[i].il > q || st[i].ir < p) return -1;
//     if (p <= st[i].il && st[i].ir <= q) return 1;
//     int lhs = simque(i * 2, p, q), rhs = simque(i * 2 + 1, p, q);
//     return lhs + rhs;
// }

void print(int i) {
    cout << st[i].il << " " << st[i].ir << " " << st[i].ans << "\n";
    for (ii i : st[i].vl) cout << i << " ";
    cout << "\n";
    for (ii i : st[i].vr) cout << i << " ";
    cout << "\n---------\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    // a[4] = 4;
    // update(4, 1);
    // for (int i = 1; i <= n * 4; ++i) {
    //     print(i);
    // }
    // st[100] = query(1, 3, 5);
    // cout << query(1, 3, 5).ans << "\n";
    // print(100);
    // cout << "fuck\n";
    // TNode t;
    // t.il = 1; t.ir = 2;
    // TNode a = t + st[5];
    while (m--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            a[x] = y;
            update(x, 1);
        } else cout << query(1, x, y).ans << "\n";
    }
    // for (int i = 1; i <= n * 4; ++i)
    //     print(i);
    return 0;
}
