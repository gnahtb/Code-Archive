#include <bits/stdc++.h>

using namespace std;

const int N = 2002;

int n, m, q, dis[N][N];
vector<int> a[N];
vector<pair<int, int>> des;

void bfs(int u, int (&d)[N]) {
    queue<int> q;
    memset(d, -1, sizeof(d));
    d[u] = 0;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v : a[u]) if (d[v] < 0) {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ysys.in", "r", stdin);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) bfs(i, dis[i]);
    int cur = 0, xdis = INT_MAX, pc, pcc;
    for (int i = 1; i <= q; ++i) {
        int d, c;
        cin >> d >> c;
        if (i == 1) {
            xdis = d;
            pcc = c;
        } else {
            int dt = dis[pc][c];
            cur += dt;
            if (cur > d) {
                cout << 0;
                return 0;
            }
            xdis = min(xdis, d - cur);
        }
        pc = c;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (dis[pcc][i] >= 0 && dis[pcc][i] <= xdis) ++ans;
    cout << ans;
    return 0;
}