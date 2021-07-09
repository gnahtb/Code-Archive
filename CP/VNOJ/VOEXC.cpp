#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

const int N = 1e5 + 2;

int n, a[N][2];
double ans;

void solve(int x) {
    vector<ii> v;
    int p = 0;
    double s = 0, c = 0;
    v.clear();
    for (int i = 1; i <= n; ++i) {
        v.emplace_back(a[i][0] + a[i][1], a[i][x]);
        p += a[i][x];
    }
    sort(v.begin(), v.end(), [](ii& lhs, ii& rhs) {
        return lhs.fi  * rhs.se > rhs.fi * lhs.se;
    });
    for (int i = 0; i < n; ++i) {
        double t = p - s;
        double u = min(t / v[i].fi, 1.0);
        s += u * v[i].fi;
        c += u * v[i].se;
        if (s >= p) break;
    }
    ans = max(ans, (double)p - c);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 2; ++j)
            cin >> a[i][j];
    solve(0);
    solve(1);
    (cout << fixed).precision(10);
    cout << ans << endl;
    return 0;
}