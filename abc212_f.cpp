#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int N = 1e5 + 2, M = 1e5 + 2, K = 17, Q = 1e5 + 2;

int n, m, q;
pair<int, int> tab[M][K], ans[Q];
vector<pair<pair<int, int>, pair<int, int>>> edges, queries;
vector<int> adj[N];

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int u, v, s, t;
        cin >> u >> v >> s >> t;
        edges.push_back(make_pair(make_pair(s, t + 1), make_pair(u, v)));
    }
    for (int i = 0; i < q; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        queries.push_back(make_pair(make_pair(x, i), make_pair(y, z)));
    }
    sort(edges.begin(), edges.end());
    sort(queries.begin(), queries.end());
    memset(tab, -1, sizeof(tab));
    int j = m - 1;
    for (int i = q - 1; i >= 0; --i) {
        while (edges[j].first.first >= queries[i].first.first) {
            int u = edges[j].second.first, v = edges[j].second.second;
            adj[u].push_back(j);
            int l = 0, r = sz(adj[v]) - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (edges[adj[v][mid]].first.first >= edges[j].second.second) {
                    tab[j][0] = make_pair(adj[v][mid], edges[adj[v][mid]].first.second - edges[adj[v][mid]].first.first - 1);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            for (int k = 1; k < K; ++k) {
                if (tab[j][k - 1].first < 0) break;
                tab[j][k] = make_pair(tab[tab[j][k - 1].first][k - 1].first, tab[j][k - 1].second + tab[tab[j][k - 1].first][k - 1].second);
            }
            --j;
        }
        int x = queries[i].first.first;
        int u = queries[i].second.first;
        int l = 0, r = sz(adj[u]);
        int go = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (x <= edges[adj[u][mid]].first.first) {
                go = adj[u][mid];
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (go < 0) {
            ans[queries[i].first.second].first = queries[i].second.first;
            ans[queries[i].first.second].second = -1;
        } else {
            int sumtime = 0;
            for (int k = K - 1; k >= 0; --k)
                if (queries[i].first.first >> k & 1) {
                    if (tab[go][k].first > 0) {
                        if (sumtime + tab[go][k].second <= queries[i].second.second) {
                            go = tab[go][k].first;
                            sumtime += tab[go][k].second;
                        } else {
                            ans[queries[i].first.second] = edges[tab[go][k].first].second;
                        }
                    }
                }
            if (ans[queries[i].first.second].first < 0)
                ans[queries[i].first.second].first = edges[go].second.second;
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i].first << " ";
        if (ans[i].second >= 0) cout << ans[i].second;
        cout << "\n";
    }
    return 0;
}