#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 1002;

int n, m, k, lab[N], cnt[N], nn;
vector<pair<int, int>> q;
set<int> a[N];

int tin[N], fup[N], cp[N], _n, tmr;
stack<int> sk;
void dfs(int u, int p) {
    cp[u] = _n;
    tin[u] = fup[u] = ++tmr;
    sk.push(u);

    for (int v : a[u]) if (v != p) {
        if (tin[v] == 0) {
            dfs(v, u);
            fup[u] = min(fup[u], fup[v]);
        } else {
            fup[u] = min(fup[u], tin[v]);
        }
    }

    if (tin[u] == fup[u]) {
        ++nn;
        while (true) {
            int t = sk.top();
            sk.pop();
            lab[t] = nn;
            ++cnt[nn];
            if (t == u) break;
        }
    }
}

int dok[N], dus[N];
void bfs(int u, int (&d)[N]) {
    queue<int> q;
    q.push(u);
    memset(d, -1, sizeof d);
    d[u] = 0;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int v : a[u]) if (d[v] < 0) {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        int s, t;
        cin >> s >> t;
        q.emplace_back(s, t);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].insert(v);
        a[v].insert(u);
    }

    for (int i = 1; i <= n; ++i)
        if (tin[i] == 0) {
            ++_n;
            dfs(i, 0);
        }

    for (pair<int, int> i : q) {
        if (cp[i.fi] != cp[i.se]) {
            cout << "0\n";
            continue;
        }
        bfs(i.fi, dok);
        bfs(i.se, dus);

        bool ans = true;
        for (int u = 1; u <= n; ++u) {
            if (dus[u] < 0) continue;
            if (cnt[lab[u]] > 2 && dus[u] < dok[u]) {
                ans = false;
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}