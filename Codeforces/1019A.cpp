#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

typedef long long ll;

const int M = 3005;

int n, m;
ll ans = LLONG_MAX;
vector<int> a[M];

void solve() {
    for (int i = 2; i <= m; ++i) sort(a[i].begin(), a[i].end());
    for (int x = sz(a[1]); x <= n; ++x) {
        int cnt = sz(a[1]);
        ll tmp = 0;
        vector<int> v;
        for (int i = 2; i <= m; ++i)
            for (int j = 0; j < sz(a[i]); ++j)
                if (sz(a[i]) - j >= x) ++cnt, tmp += a[i][j];
                else v.push_back(a[i][j]);
        sort(v.begin(), v.end());
        for (int j = 0; j < sz(v); ++j)
            if (cnt < x) ++cnt, tmp += v[j]; else break;
        if (cnt == x) ans = min(ans, tmp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int p, c;
        cin >> p >> c;
        a[p].push_back(c);
    }
    solve();
    cout << ans << "\n";
    return 0;
}
