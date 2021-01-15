#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 2;

int n, m;
vector<pair<tuple<int, int, int>, int>> a[N][2][2];
ll dis[N][2][2];
bool vis[N][2][2];
priority_queue<pair<ll, tuple<int, int, int>>> pq;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        a[u][0][0].emplace_back(make_tuple(v, 0, 0), w);
        a[u][0][0].emplace_back(make_tuple(v, 0, 1), w * 2);
        a[u][0][0].emplace_back(make_tuple(v, 1, 0), 0);
        a[u][0][0].emplace_back(make_tuple(v, 1, 1), w);
        a[u][0][1].emplace_back(make_tuple(v, 0, 1), w);
        a[u][0][1].emplace_back(make_tuple(v, 1, 1), 0);
        a[u][1][0].emplace_back(make_tuple(v, 1, 0), w);
        a[u][1][0].emplace_back(make_tuple(v, 1, 1), w * 2);
        a[u][1][1].emplace_back(make_tuple(v, 1, 1), w);

        a[v][0][0].emplace_back(make_tuple(u, 0, 0), w);
        a[v][0][0].emplace_back(make_tuple(u, 0, 1), w * 2);
        a[v][0][0].emplace_back(make_tuple(u, 1, 0), 0);
        a[v][0][0].emplace_back(make_tuple(u, 1, 1), w);
        a[v][0][1].emplace_back(make_tuple(u, 0, 1), w);
        a[v][0][1].emplace_back(make_tuple(u, 1, 1), 0);
        a[v][1][0].emplace_back(make_tuple(u, 1, 0), w);
        a[v][1][0].emplace_back(make_tuple(u, 1, 1), w * 2);
        a[v][1][1].emplace_back(make_tuple(u, 1, 1), w);
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                dis[i][j][k] = LLONG_MAX;
            }
        }
    }
    dis[1][0][0] = 0;
    pq.emplace(0, make_tuple(1, 0, 0));
    while (!pq.empty()) {
        int u, ua, ub;
        tie(u, ua, ub) = pq.top().second;
        pq.pop();
        if (vis[u][ua][ub]) continue;
        vis[u][ua][ub] = true;
        for (auto i : a[u][ua][ub]) {
            int v, va, vb;
            tie(v, va, vb) = i.first;
            if (dis[v][va][vb] > dis[u][ua][ub] + i.second) {
                dis[v][va][vb] = dis[u][ua][ub] + i.second;
                pq.emplace(-dis[v][va][vb], i.first);
            }
        }
    }
    for (int i = 2; i <= n; ++i) cout << dis[i][1][1] << " ";
    return 0;
}