#include <bits/stdc++.h>

#define sz(a) (int)a.size()
#define X first
#define Y second

using namespace std;

const int oo = INT_MAX;

struct Dinic {
    int n, m;
    vector<vector<int>> adj;
    vector<int> ptr, lvl, que;
    vector<array<int, 2>> edge, capa, flow;

    inline void Reset() {
        adj.clear();
        ptr.clear();
        lvl.clear();
        que.clear();
        edge.clear();
        capa.clear();
        flow.clear();
    }

    void Init(int nn) {
        n = nn;
        m = 0;
        adj.resize(n + 2);
        ptr.resize(n + 2);
        lvl.resize(n + 2);
        que.resize(n + 2);
    }

    void AddEdge(int u, int v, int c, int rc = 0) {
        adj[u].push_back(m);
        adj[v].push_back(m++);
        edge.push_back({u, v});
        capa.push_back({c, rc});
        flow.push_back({0, 0});
    }

    inline bool Rev(int i, int u) {
        return edge[i][1] == u;
    }

    bool Level(int s, int t) {
        int head = 0, tail = 1;
        fill(lvl.begin(), lvl.end(), -1);
        lvl[s] = 0;
        que[0] = s;
        while (head < tail) {
            int u = que[head++];
            for (int i : adj[u]) {
                bool flag = Rev(i, u);
                int v = edge[i][flag ^ 1];
                if (lvl[v] < 0 && flow[i][flag] < capa[i][flag]) {
                    lvl[v] = lvl[u] + 1;
                    que[tail++] = v;
                }
            }
        }
        return lvl[t] > 0;
    }

    int DFS(int u, int t, int fcur) {
        if (fcur <= 0) return 0;
        if (u == t) return fcur;
        for (; ptr[u] < sz(adj[u]); ++ptr[u]) {
            int i = adj[u][ptr[u]];
            bool flag = Rev(i, u);
            int v = edge[i][flag ^ 1];
            if (lvl[v] == lvl[u] + 1 && flow[i][flag] < capa[i][flag]) {
                int pushed = DFS(v, t, min(fcur, capa[i][flag] - flow[i][flag]));
                if (pushed > 0) {
                    flow[i][flag] += pushed;
                    flow[i][flag ^ 1] -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int MaxFlow(int s, int t) {
        int maxflow = 0;
        while (Level(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int fcur = DFS(s, t, oo))
                maxflow += fcur;
        }
        return maxflow;
    }

    void Trace(int s, int t, vector<int>& res) {
        // Level(s, t);
        for (int i = 0; i < m; ++i) {
            if (flow[i][0] > 0) {
                res.push_back(i);
            }
        }
    }
} nw;

const int LIM = 10002;

int test, n, m;
pair<int, int> wire[LIM];
int nodes, s, t, cur[LIM];

// 0 -> X down to Y
// 1 -> Y up to X
int sol[LIM][2];

void Build() {
    nodes = n + m * 4 + 2;
    s = nodes - 1;
    t = nodes;
    nw.Reset();
    nw.Init(nodes);
    for (int i = 1; i <= n; ++i) {
        nw.AddEdge(s, i, 1);
        cur[i] = i;
    }
    int cidx = n;
    for (int i = 1; i <= m; ++i) {
        nw.AddEdge(cur[wire[i].X], ++cidx, oo);
        nw.AddEdge(cur[wire[i].Y], cidx, oo);
        nw.AddEdge(cidx, cidx + 1, 1);
        ++cidx;
        sol[i][1] = nw.m; nw.AddEdge(cidx, cidx + 1, oo);
        sol[i][0] = nw.m; nw.AddEdge(cidx, cidx + 2, oo);
        cur[wire[i].X] = ++cidx;
        cur[wire[i].Y] = ++cidx;
    }
    for (int i = 1; i <= n; ++i) {
        nw.AddEdge(cur[i], t, 1);
    }
}

int Bit(int b, int i) {
    return b >> i & 1;
}

bool flag[LIM * 100];

void SolveSmall() {
    // 0 -> X downto Y
    // 1 -> Y upto X
    for (int mk = 0; mk < 1 << m; ++mk) {
        fill(flag + 1, flag + n + 1, false);
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int cur = i;
            for (int j = 1; j <= m; ++j) {
                if (Bit(mk, j - 1) && cur == wire[j].Y) cur = wire[j].X;
                if (!Bit(mk, j - 1) && cur == wire[j].X) cur = wire[j].Y;
            }
            if (!flag[cur]) ++cnt;
            flag[cur] = true;
        }
        if (cnt >= (n + 1) / 2) {
            for (int j = 1; j <= m; ++j)
                if (Bit(mk, j - 1)) cout << "^";
                else cout << "v";
            cout << "\n";
            return;
        }
    }
    cout << "failure\n";
}

void SolveBig() {
    Build();
    int maxcnt = nw.MaxFlow(s, t);
    // cout << maxcnt << " ";
    if (maxcnt < (n + 1) / 2) {
        cout << "failure\n";
    } else {
        vector<int> used;
        // nw.Trace(s, t, used);
        for (int i = 1; i <= m; ++i) {
            if (nw.flow[sol[i][0]][0] > 0) {
                cout << "v";
            } else {
                cout << "^";
            }
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> test;
    while (test--) {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i)
            cin >> wire[i].X >> wire[i].Y;
        if (m <= 10) {
            SolveSmall();
        } else {
            SolveBig();
        }
    }
    return 0;
}