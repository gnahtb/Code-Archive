#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2, K = 17;

int n, q, d[N], fup[N][K];
vector<int> a[N];

void dfs(int u) {
    for (int i = 1; i < K; ++i) {
        if (fup[u][i - 1] < 0) break;
        fup[u][i] = fup[fup[u][i - 1]][i - 1];
    }
    for (int v : a[u]) if (v != fup[u][0]) {
        fup[v][0] = u;
        d[v] = d[u] + 1;
        dfs(v);
    }
}

int LCA(int u, int v) {
    // d[u] <= d[v]
    if (d[u] > d[v]) swap(u, v);
    int delta = d[v] - d[u];
    for (int i = 0; i < K; ++i)
        if (delta >> i & 1) v = fup[v][i];
    if (u == v) return u;
    for (int i = K - 1; i >= 0; --i) {
        if (fup[u][i] != fup[v][i]) {
            u = fup[u][i];
            v = fup[v][i];
        }
    }
    return fup[u][0];
}

int main() {
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(fup, -1, sizeof(fup));
    dfs(1);
    while (q--) {
        int u, v;
        cin >> u >> v;
        int w = LCA(u, v);
        int uw = d[u] - d[w];
        int vw = d[v] - d[w];
        cout << (uw % 2 == vw % 2 ? "Town\n" : "Road\n");
    }
    return 0;
}