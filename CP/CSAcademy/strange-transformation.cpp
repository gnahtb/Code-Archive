#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()
#define fi first
#define se second

typedef pair<int, int> ii;

int n, x = 0;
ii a, b;
vector<ii> v;
vector<int> ans;

ii getPower(int &p) {
    ii r = {0, 0}; 
    while (!(p % 2)) ++r.fi, p /= 2;
    while (!(p % 3)) ++r.se, p /= 3;
    return r;
}

int getNumber(ii &p) {
    int r = x;
    for (int i = 0; i < p.fi; ++i) r *= 2;
    for (int i = 0; i < p.se; ++i) r *= 3;
    return r;
}

void check() {
    if (v[0].fi > a.fi || v[0].se < a.se) { cout << "-1\n"; exit(0); }
    if (v.back().fi < b.fi || v.back().se > b.se) { cout << "-1\n"; exit(0); }
    for (int i = 1; i < sz(v); ++i)
        if (v[i - 1].fi < v[i].fi || v[i - 1].se > v[i].se) { cout << "-1\n"; exit(0); }
}

void solve() {
    v.push_back(a); v.push_back(b);
    sort(v.begin(), v.end(), [](ii p, ii q) {
       return p.fi == q.fi ? p.se < q.se : p.fi > q.fi; 
    });
    ans.push_back(getNumber(v[0]));
    for (int i = 1; i < sz(v); ++i) {
        while (v[i - 1].fi > v[i].fi)
            --v[i - 1].fi, ans.push_back(getNumber(v[i - 1]));
        while (v[i - 1].se < v[i].se)
            ++v[i - 1].se, ans.push_back(getNumber(v[i - 1]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n + 2; ++i) {
        int t;
        cin >> t;
        if (!i) a = getPower(t);
        else if (i == 1) b = getPower(t);
        else v.push_back(getPower(t));
        if (!x) x = t;
        else if (x != t) { cout << "-1\n"; return 0; }
    }
    sort(v.begin(), v.end(), [](ii p, ii q) {
       return p.fi == q.fi ? p.se < q.se : p.fi > q.fi; 
    });
    if (a.fi < b.fi || a.se > b.se) { cout << "-1\n"; return 0; }
    if (n) check();
    solve();
    for (int i : ans) cout << i << " ";
    return 0;
}