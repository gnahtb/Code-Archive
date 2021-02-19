#include <bits/stdc++.h>

#define sqr(a) (a) * (a)

using namespace std;

const int N = 1e5 + 2, K = 52;

int n, m, ans[N], dis[N][2][K];
bool vis[N][2][K];
vector<pair<int, int>> adj[N];
priority_queue<tuple<int, int, int, int>> q;

void reset() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < K; ++k)
                dis[i][j][k] = INT_MAX, vis[i][j][k] = false;
    for (int i = 0; i < N; ++i) ans[i] = INT_MAX;
}

void dijsktra() {
    reset();
    dis[1][0][0] = 0;
    q.emplace(0, 1, 0, 0);
    while (!q.empty()) {
        int u, i, j;
        tie(ignore, u, i, j) = q.top();
        q.pop();
        if (vis[u][i][j]) continue;
        vis[u][i][j] = true;
        if (i == 0) ans[u] = min(ans[u], dis[u][0][j]);
        for (pair<int, int> it : adj[u]) {
            int v, w;
            tie(v, w) = it;
            if (i == 0) {
                if (dis[u][0][j] < dis[v][1][w]) {
                    dis[v][1][w] = dis[u][0][j];
                    q.emplace(-dis[v][1][w], v, 1, w);
                }
            } else {
                if (dis[u][1][j] + sqr(j + w) < dis[v][0][w]) {
                    dis[v][0][w] = dis[u][1][j] + sqr(j + w);
                    q.emplace(-dis[v][0][w], v, 0, w);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int v, u, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dijsktra();
    for (int i = 1; i <= n; ++i) {
        cout << (ans[i] >= 1000000000 ? -1 : ans[i]) << " ";
    }
    return 0;
}