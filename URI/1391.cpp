#include <bits/stdc++.h>

using namespace std;

const int N = 502;

int n, m, s, d, diss[N], disd[N], disf[N];
vector<pair<int, int>> adj[N];
vector<pair<int, int>> radj[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
bool vis[N];

void dijkstra(int s, int *dis) {
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; ++i) {
        dis[i] = INT_MAX;
        vis[i] = false;
    }
    dis[s] = 0;
    q.emplace(0, s);
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (pair<int, int> i : adj[u]) {
            int v = i.first, w = i.second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.emplace(dis[v], v);
            }
        }
    }
}

void dijkstra2(int s, int *dis) {
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; ++i) {
        dis[i] = INT_MAX;
        vis[i] = false;
    }
    dis[s] = 0;
    q.emplace(0, s);
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (pair<int, int> i : radj[u]) {
            int v = i.first, w = i.second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.emplace(dis[v], v);
            }
        }
    }
}

void dijkstra1() {
    for (int i = 1; i <= n; ++i) {
        disf[i] = INT_MAX;
        vis[i] = false;
    }
    disf[s] = 0;
    q.emplace(0, s);
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (pair<int, int> i : adj[u]) {
            int v = i.first, w = i.second;
            if (diss[u] + w + disd[v] == diss[d]) continue;
            if (disf[u] + w < disf[v]) {
                disf[v] = disf[u] + w;
                q.emplace(disf[v], v);
            }
        }
    }
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0) break;
        cin >> s >> d;
        ++s;
        ++d;
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            radj[i].clear();
        }
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            ++u;
            ++v;
            adj[u].emplace_back(v, w);
            radj[v].emplace_back(u, w);
        }
        dijkstra(s, diss);
        dijkstra2(d, disd);
        // for (int i = 1; i <= n; ++i) cout << diss[i] << " ";
        // cout << "\n";
        // for (int i = 1; i <= n; ++i) cout << disd[i] << " ";
        dijkstra1();
        if (disf[d] == INT_MAX) {
            cout << "-1\n";
        } else {
            cout << disf[d] << "\n";
        }
    }
    return 0;
}