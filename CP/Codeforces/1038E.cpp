#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

typedef pair<int, int> ii;

const int N_MAX = 105, NODES_MAX = 4, MASK_MAX = 1 << NODES_MAX;

struct TEdge { int u, v, w; };
struct TGraph {
    vector<int> nodes;
    vector<ii> adj[NODES_MAX], cut_edges;
    int sum = 0, wmin[NODES_MAX][NODES_MAX];

    TGraph() { fill(wmin[0], wmin[NODES_MAX], INT_MAX); }

    int id(int x) {
        for (int i = 0; i < sz(nodes); ++i) if (nodes[i] == x) return i;
        return -1;
    }

    void find_cut_edges(int u, int& timer, bool* vis, int* tin, int* fup) {
        tin[u] = fup[u] = ++timer;
        for (ii t : adj[u]) {
            int v = t.first, i = t.second;
            if (vis[i]) continue;
            vis[i] = true;
            if (!tin[v]) {
                find_cut_edges(v, timer, vis, tin, fup);
                fup[u] = min(fup[u], fup[v]);
                if (fup[v] > tin[u]) cut_edges.push_back({u, v});
            } else fup[u] = min(fup[u], tin[v]);
        }
    }
};

int n, ans = 0;
vector<TEdge> e;

int dis[MASK_MAX], pre[MASK_MAX];
bool avail[MASK_MAX];
priority_queue<ii, vector<ii>, greater<ii>> q;

inline int bit(int m, int i) { return m >> i & 1; }

void build_graph(int m, TGraph &g) {
    for (int i = 0; i < 4; ++i) if (bit(m, i)) g.nodes.push_back(i);
    for (int i = 0; i < sz(e); ++i) {
        TEdge t = e[i];
        if (!bit(m, t.u) || !bit(m, t.v)) continue;
        g.sum += t.w;
        if (t.u == t.v) continue;
        g.adj[t.u].push_back({t.v, i});
        g.adj[t.v].push_back({t.u, i});
        g.wmin[t.u][t.v] = min(g.wmin[t.u][t.v], t.w);
        g.wmin[t.v][t.u] = min(g.wmin[t.v][t.u], t.w);
    }
}

int min_removal_cost(TGraph &g) {
    int cur = 0, cost = INT_MAX;
    fill(dis, dis + MASK_MAX, INT_MAX);
    fill(pre, pre + MASK_MAX, -1);
    fill(avail, avail + MASK_MAX, true);
    for (int i = 0; i < sz(g.nodes); ++i)
        cur |= (sz(g.adj[g.nodes[i]]) & 1) << i;
    dis[cur] = 0; q.push({0, cur});
    while (!q.empty()) {
        cur = q.top().second; q.pop();
        if (!avail[cur]) continue;
        for (int u : g.nodes) for (int v : g.nodes)
            if (u < v && g.wmin[u][v] < INT_MAX) {
                int nxt = cur ^ (1 << g.id(u)) ^ (1 << g.id(v));
                if (nxt == pre[cur]) continue;
                if (dis[nxt] > dis[cur] + g.wmin[u][v]) {
                    dis[nxt] = dis[cur] + g.wmin[u][v];
                    pre[nxt] = cur;
                    q.push({dis[nxt], nxt});
                }
            }
    }
    for (int m = 0; m < 1 << sz(g.nodes); ++m) if (dis[m] < INT_MAX) {
        int b1 = __builtin_popcount(m);
        if (b1 == 0 || b1 == 2) cost = min(cost, dis[m]);
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int c1, c2, v;
        cin >> c1 >> v >> c2;
        e.push_back({--c1, --c2, v});
    }
    for (int m = 1; m < MASK_MAX; ++m) {
        int timer = 0, tin[NODES_MAX], fup[NODES_MAX];
        bool vis[N_MAX], flag = true;
        TGraph g;
        build_graph(m, g);
        fill(tin, tin + NODES_MAX, 0);
        fill(vis, vis + N_MAX, false);
        g.find_cut_edges(g.nodes[0], timer, vis, tin, fup);
        for (int u : g.nodes)
            flag &= (tin[u] > 0);
        if (!flag) continue;
        for (ii i : g.cut_edges)
            g.wmin[i.first][i.second] = g.wmin[i.second][i.first] = INT_MAX;
        int cost = min_removal_cost(g);
        if (cost < INT_MAX) ans = max(ans, g.sum - cost);
    }
    cout << ans << "\n";
    return 0;
}
