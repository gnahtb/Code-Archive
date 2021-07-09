#include <bits/stdc++.h>

#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()

using namespace std;

const int oo = 0x3f3f3f;

struct Network {
    int n, m, s, t;
    vector<vector<int>> adj;
    vector<array<int, 2>> edges, cap, flow;;
    vector<int> lv, qu, ptr;

    void Reset() {
        n = m = s = t = 0;
        adj.clear();
        edges.clear();
        cap.clear();
        flow.clear();
        lv.clear();
        qu.clear();
        ptr.clear();
    }

    void Init(int _n, int _s, int _t) {
        n = _n;
        s = _s;
        t = _t;
        adj.resize(n + 2);
        lv.resize(n + 2);
        qu.resize(n + 2);
        ptr.resize(n + 2);
    }

    void AddEdge(int u, int v, int c, int rc = 0) {
        adj[u].push_back(m);
        adj[v].push_back(m++);
        edges.push_back({u, v});
        cap.push_back({c, rc});
        flow.push_back({0, 0});
    }

    bool Rev(int i, int u) {
        return edges[i][1] == u;
    }

    bool BFS() {
        fill(lv.begin(), lv.end(), -1);
        int head = 0, tail = 0;
        qu[0] = s;
        lv[s] = 0;
        while (head <= tail) {
            int u = qu[head++];
            for (int i : adj[u]) {
                bool flag = Rev(i, u);
                int v = edges[i][flag ^ 1];
                if (lv[v] < 0 && cap[i][flag] > flow[i][flag]) {
                    lv[v] = lv[u] + 1;
                    qu[++tail] = v;
                }
            }
        }
        return lv[t] >= 0;
    }

    int DFS(int u, int curflow) {
        if (curflow <= 0) return 0;
        if (u == t) return curflow;
        for (; ptr[u] < sz(adj[u]); ++ptr[u]) {
            int i = adj[u][ptr[u]];
            bool flag = Rev(i, u);
            int v = edges[i][flag ^ 1];
            if (lv[v] == lv[u] + 1 && cap[i][flag] > flow[i][flag]) {
                int pushed = DFS(v, min(curflow, cap[i][flag] - flow[i][flag]));
                if (pushed > 0) {
                    flow[i][flag] += pushed;
                    flow[i][flag ^ 1] -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int MaxFlow() {
        int ret = 0;
        while (BFS()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int fc = DFS(s, oo)) {
                ret += fc;
            }
        }
        return ret;
    }
} net;

const int LIM = 12;
const int Dirs = 4;
const pair<int, int> D[Dirs] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int test;
int n;
vector<pair<int, int>> cells[LIM];

int GetIdx(pair<int, int> cell, vector<pair<int, int>>& vcell) {
    if (!binary_search(all(vcell), cell)) return -1;
    return lower_bound(all(vcell), cell) - vcell.begin() + 1;
}

bool CheckCell(int i, int j) {
    return 0 < i && i <= n && 0 < j && j <= n;
}

bool Solve(int x) {
    net.Reset();
    int t = sz(cells[x]) + sz(cells[x + 1]) + 2;
    int s = t - 1;
    net.Init(t, s, t);
    for (int i = 0; i < sz(cells[x]); ++i) {
        net.AddEdge(s, i + 1, 1);
        for (int j = 0; j < Dirs; ++j) {
            pair<int, int> v;
            v.first = cells[x][i].first + D[j].first;
            v.second = cells[x][i].second + D[j].second;
            if (CheckCell(v.first, v.second)) {
                int idv = GetIdx(v, cells[x + 1]);
                if (idv > 0) {
                    net.AddEdge(i + 1, idv + sz(cells[x]), oo);
                }
            }
        }
    }
    for (int i = 0; i < sz(cells[x + 1]); ++i) {
        net.AddEdge(i + sz(cells[x]) + 1, t, 1);
    }
    int maxflow = net.MaxFlow();
    return maxflow == sz(cells[x + 1]);
}

int main() {
	ios::sync_with_stdio(false);
    cin >> test;
    while (test--) {
        for (int i = 1; i < LIM; ++i) cells[i].clear();
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int a;
                cin >> a;
                cells[a].emplace_back(i, j);
            }
        }
        for (int i = 1; i < LIM; ++i) sort(all(cells[i]));
        bool ans = true;
        for (int i = 1; i < 10; ++i) {
            if (!Solve(i)) {
                ans = false;
                break;
            }
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}