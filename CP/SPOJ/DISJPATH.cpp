#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

const int INF = 1e9;

const int N_MAX = 10005;

int k, n;

int m;
vector<array<int, 2>> edges, cap, flow;
vector<int> adj[N_MAX];

inline void reset() {
    edges.clear();
    cap.clear();
    flow.clear();
    for (int i = 1; i <= n + n; ++i) adj[i].clear();
}

void add_edge(int u, int v, int w, int rw) {
    edges.push_back({u, v});
    cap.push_back({w, rw});
    flow.push_back({0, 0});
    adj[u].push_back(sz(edges) - 1);
    adj[v].push_back(sz(edges) - 1);
}

bool chk[N_MAX];
void enter() {
    for (int i = 1; i <= n; ++i) {
        memset(chk, false, sizeof chk);
        add_edge(i, i + n, i < 3 ? INF : 1, 0);
        int cur = 0;
        char ch;
        while (scanf("%c", &ch)) {
            if ('0' <= ch && ch <= '9') (cur *= 10) += ch - '0';
            else {
                // if (cur) add_edge(i + n, cur, i < 3 && cur < 3 ? 1 : INF, 0);
                if (cur) chk[cur] = true;
                cur = 0;
            }
            if (ch == '\n') break;
        }
        for (int j = 1; j <= n; ++j)
            if (chk[j]) add_edge(i + n, j, i < 3 && j < 3 ? 1 : INF, 0);
    }
}

inline bool is_rev(int i, int u) {
    return edges[i][1] == u;
}

deque<int> q;
int fcur[N_MAX], pre[N_MAX];
int find_augmenting_path(int s, int t) {
    q.clear();
    memset(fcur, -1, sizeof fcur);
    memset(pre, -1, sizeof pre);
    fcur[s] = INF; q.push_back(s);
    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        if (u == t) return fcur[t];
        for (int i : adj[u]) {
            bool d = is_rev(i, u);
            int v = edges[i][d ^ 1];
            if (fcur[v] >= 0 || flow[i][d] >= cap[i][d]) continue;
            fcur[v] = min(fcur[u], cap[i][d] - flow[i][d]);
            pre[v] = i;
            q.push_back(v);
        }
    }
    return -1;
}

void inc_flow(int u, int x, int y) {
    while (pre[u] >= 0) {
        int i = pre[u];
        bool t = is_rev(i, u);
        flow[i][t ^ 1] += x;
        flow[i][t] -= y;
        u = edges[i][t ^ 1];
    }
}

vector<int> p;
bool find_flow(int u, int x, int t) {
    if (u <= n) p.push_back(u);
    if (u == t) {
        for (int i : p) printf("%d ", i);
        printf("\n");
        p.clear();
        return true;
    }
    for (int i : adj[u]) {
        bool d = is_rev(i, u);
        int v = edges[i][d ^ 1];
        if (flow[i][d] > 0) {
            bool tmp = find_flow(v, x, t);
            if (tmp) {
                flow[i][d] -= x;
                return true;
            }
        }
    }
    p.pop_back();
    return false;
}

void solve() {
    int fs = 0;
    while (fs < k) {
        int f = find_augmenting_path(1, 2 + n);
        if (f <= 0) break;
        fs += f;
        inc_flow(2 + n, f, f);
    }
    if (fs < k) {
        printf("Impossible\n");
        return;
    }
    for (; fs; --fs) find_flow(1, 1, 2 + n);
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("inp.txt", "r", stdin);
    int itest = 0;
    while (scanf("%d%d\n", &k, &n)) {
        if (n == 0) break;
        reset();
        enter();
        printf("Case %d:\n", ++itest);
        solve();
        printf("\n");
    }
    return 0;
}