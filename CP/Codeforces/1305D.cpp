#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)a.size()

using namespace std;

const int N = 1002;

int n, re;
vector<pair<int, int>> edges;
vector<vector<int>> adj;
vector<bool> flag;
vector<int> leaves;

void DFS(int u, int ban) {
    flag[u] = false;
    --re;
    for (int v : adj[u])
        if (v != ban && flag[v]) {
            DFS(v, ban);
        }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }
    flag.resize(n + 2, true);
    re = n;
    while (re > 1) {
        adj.clear();
        adj.resize(n + 2);
        leaves.clear();
        for (pair<int, int> i : edges) {
            if (flag[i.fi] && flag[i.se]) {
                adj[i.fi].push_back(i.se);
                adj[i.se].push_back(i.fi);
            }
        }
        for (int i = 1; i <= n; ++i)
            if (flag[i] && sz(adj[i]) < 2)
                leaves.push_back(i);
        if (sz(leaves) == 1) {
            cout << leaves[0] << "\n";
            cout.flush();
            return 0;
        }
        int u = leaves[0], v = leaves[1];
        cout << "? " << u << " " << v << "\n";
        cout.flush();
        int lca;
        cin >> lca;
        if (lca == u || lca == v) {
            cout << "! " << lca << "\n";
            cout.flush();
            return 0;
        }
        DFS(u, lca);
        DFS(v, lca);
    }
    for (int i = 1; i <= n; ++i) if (flag[i]) {
        cout << "! " << i << "\n";
        cout.flush();
        return 0;
    }
    return 1;
}
