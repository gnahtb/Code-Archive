#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int n, m, k, p[N], layer[N], ansmin = 0, ansmax = 0;
vector<int> adj[N], adj1[N];

void BFS() {
    queue<int> q;
    while (!q.empty()) q.pop();
    memset(layer, -1, sizeof(layer));
    q.push(p[k]);
    layer[p[k]] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) if (layer[v] < 0) {
            layer[v] = layer[u] + 1;
            q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj1[u].push_back(v);
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) cin >> p[i];
    BFS();
    for (int i = 1; i < k; ++i) {
        if (layer[p[i]] - 1 != layer[p[i + 1]]) {
            ++ansmin;
            ++ansmax;
        } else {
            for (int j : adj1[p[i]]) {
                if (j != p[i + 1] && layer[j] == layer[p[i]] - 1) {
                    ++ansmax;
                    break;
                }
            }
        }
    }
    cout << ansmin << " " << ansmax << "\n";
    return 0;
}
