#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;

const int N = 1E5 + 5;

int n, m, d, f[N], ans = 0;
ii t[N][2];
bool aff[N];
vector<int> a[N];

void enter() {
    memset(aff, false, sizeof aff);
    cin >> n >> m >> d;
    for (int i = 1; i <= m; ++i) {
        int p;
        cin >> p;
        aff[p] = true;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
}

void calcDown(int u, int p) {
    if (aff[u]) t[u][0] = {0, u};
    for (int v : a[u]) if (v != p) {
        calcDown(v, u);
        if (t[v][0].fi == -1) continue;
        if (t[v][0].fi >= t[u][0].fi) {
            t[u][1] = t[u][0];
            t[u][0] = {t[v][0].fi + 1, v};
        } else if (t[v][0].fi >= t[u][1].fi)
            t[u][1] = {t[v][0].fi + 1, v};
    }
}

void calcUp(int u, int p, int c) {
    f[u] = max(c, t[u][0].fi);
    for (int v : a[u]) if (v != p) {
        int x = max(v == t[u][0].se ? t[u][1].fi : t[u][0].fi, c);
        if (x >= 0) ++x;
        calcUp(v, u, x);
    }
}

void solve() {
    memset(t, -1, sizeof t);
    memset(f, -1, sizeof f);
    calcDown(1, 0);
    calcUp(1, 0, -1);
    for (int i = 1; i <= n; ++i) ans += f[i] <= d;
}

int main() {
    ios_base::sync_with_stdio(false);
    enter();
    solve();
    cout << ans << "\n";
    return 0;
}
