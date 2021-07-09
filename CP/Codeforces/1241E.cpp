#include <bits/stdc++.h>

#define sz(a) (int)a.size()
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e5 + 2;

int q, n, k;
vector<pii> a[N];

// 0 -> not include parent edge
// 1 -> include parent edge
ll f[N][2];

void dfs(int u, int p = 0) {
    vector<ll> vec;
    bool leaf = true;
    ll sum = 0;
    vec.clear();
    for (int i = 0; i < sz(a[u]); ++i) {
        int v = a[u][i].fi;
        if (v == p) continue;
        leaf = false;
        dfs(v, u);
        f[v][1] += a[u][i].se;
        vec.emplace_back(f[v][1] - f[v][0]);
        sum += f[v][0];
    }
    if (leaf) {
        f[u][0] = f[u][1] = 0;
        return;
    }
    sort(vec.begin(), vec.end(), greater<ll>());

    // not take parent edge
    ll del = 0, cur = 0;
    for (int i = 0; i < min(k, sz(vec)); ++i) {
        cur += vec[i];
        del = max(del, cur);
    }
    f[u][0] = sum + del;

    // take parent edge
    del = cur = 0;
    for (int i = 0; i < min(k - 1, sz(vec)); ++i) {
        cur += vec[i];
        del = max(del, cur);
    }
    f[u][1] = sum + del;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while (q--) {
        for (int i = 1; i <= n; ++i) {
            f[i][0] = f[i][1] = 0;
            a[i].clear();
        }
        cin >> n >> k;
        for (int i = 1; i < n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            a[u].emplace_back(v, w);
            a[v].emplace_back(u, w);
        }
        dfs(1);
        ll ans = f[1][0];
        cout << ans << "\n";
    }
    return 0;
}
