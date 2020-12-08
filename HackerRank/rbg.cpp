#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int N = 1e5 + 2;

int n, q;
vector<pair<int, int>> rv[N], gv[N], bv[N];
vector<int> rf[N], gf[N], bf[N];

void fix(vector<pair<int, int>>& v, vector<int>& f) {
    sort(v.begin(), v.end());
    f.assign(sz(v), INT_MAX);
    for (int i = 0; i < sz(v); ++i) {
        if (i) f[i] = f[i - 1];
        f[i] = min(f[i], v[i].second);
    }
}

int bsearch(int x, vector<pair<int, int>>& v) {
    int l = 0, r = sz(v) - 1, res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (v[m].first <= x) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return res;
}

string Solve(int x, int y, int z) {
    int px = bsearch(y, rv[x]);
    int py = bsearch(z, gv[y]);
    int pz = bsearch(x, bv[z]);
    if (px < 0 || py < 0 || pz < 0) return "NO";
    return rf[x][px] <= z && gf[y][py] <= x && bf[z][pz] <= y ? "YES" : "NO";
}

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int r, g, b;
        cin >> r >> g >> b;
        rv[r].emplace_back(g, b);
        gv[g].emplace_back(b, r);
        bv[b].emplace_back(r, g);
    }
    for (int i = 0; i < N; ++i) {
        fix(rv[i], rf[i]);
        fix(gv[i], gf[i]);
        fix(bv[i], bf[i]);
    }
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        cout << Solve(x, y, z) << "\n";
    }
    return 0;
}