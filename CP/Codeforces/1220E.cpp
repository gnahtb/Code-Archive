#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)a.size()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 2, M = 2e5 + 2;

int n, m, s, w[N];
vector<pii> a[N];
pii e[M];
bool b[M];

int no[N];
ll ww[N];
bool re[N];
vector<int> aa[N];

int tmr = 0, tin[N], fup[N], lab[N], cnt;
bool used[M];
stack<int> stk;
void dfs(int u) {
    tin[u] = fup[u] = ++tmr;
    stk.push(u);
    for (int i = 0; i < sz(a[u]); ++i) {
        int v = a[u][i].fi;
        int p = a[u][i].se;
        if (used[p]) continue;
        used[p] = true;
        if (tin[v] > 0) {
            fup[u] = min(fup[u], tin[v]);
        } else {
            dfs(v);
            fup[u] = min(fup[u], fup[v]);
        }
    }
    if (fup[u] == tin[u]) {
        ++cnt;
        while (true) {
            int t = stk.top();
            stk.pop();
            lab[t] = cnt;
            ++no[cnt];
            ww[cnt] += w[t];
            if (u == t) break;
        }
    }
}

// 0 -> can return
// 1 -> cannot return
ll f[N][2];
void dfs1(int u, int p = 0) {
    re[u] = no[u] > 1;
    f[u][0] = f[u][1] = ww[u];
    for (int v : aa[u]) if (v != p) {
        dfs1(v, u);
        f[u][0] += f[v][0];
        re[u] |= re[v];
    }
    for (int v : aa[u]) if (v != p) {
        f[u][1] = max(f[u][1], f[u][0] - f[v][0] + f[v][1]);
    }
    if (!re[u]) {
        f[u][0] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].emplace_back(v, i);
        a[v].emplace_back(u, i);
        e[i] = {u, v};
    }
    cin >> s;
    dfs(s);
    for (int i = 1; i <= m; ++i)
        if (lab[e[i].fi] != lab[e[i].se]) {
            aa[lab[e[i].fi]].push_back(lab[e[i].se]);
            aa[lab[e[i].se]].push_back(lab[e[i].fi]);
        }
    dfs1(lab[s]);
    ll ans = max(f[lab[s]][0], f[lab[s]][1]);
    cout << ans << "\n";
    return 0;
}
