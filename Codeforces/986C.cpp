#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int M = 4194304;
const int L = M << 1;

int n, m, a[M], ans = 0;
bool vis[L];
vector<int> adj[M];

inline int getbit(int m, int i) { return m >> i & 1; }

void DFS(int u) {
    vis[u] = true;
    if (u < 1 << n) {
        for (int i = 0; i < n; ++i)
            if (!getbit(u, i) && !vis[u | (1 << i)]) DFS(u | (1 << i));
        for (int v : adj[u]) if (!vis[v]) DFS(v);
    } else if (!vis[a[u - (1 << n)]]) DFS(a[u - (1 << n)]);
}

void solve() {
    fill(vis, vis + L, false);
    for (int i = 0; i < m; ++i)
        adj[(1 << n) - 1 - a[i]].push_back((1 << n) + i);
    for (int i = 0; i < m; ++i)
        if (!vis[(1 << n) + i]) DFS((1 << n) + i), ++ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
    solve();
    printf("%d\n", ans);
    return 0;
}
