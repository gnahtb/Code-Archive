#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

#define sz(a) (int)a.size()
#define fi first
#define se second

const int LIM = 105;

int m, n, p = 0;
char ch[LIM][LIM];
vector<int> adj[2][LIM];

int edges[LIM * LIM][2];
int col[LIM * LIM];
queue<int> redges;

void enter() {
    cin >> m >> n;
    int k = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> ch[i][j];
            if (ch[i][j] == '1') {
                adj[0][i].push_back(++k);
                adj[1][j].push_back(k);
                redges.push(k);
                edges[k][0] = i;
                edges[k][1] = j;
            }
        }
}

void fix(int z, int pre, int u, int* c) {
    for (int t : adj[z][u]) {
        if (t != pre && col[t] == c[z]) {
            col[t] = c[z ^ 1];
            fix(z ^ 1, t, edges[t][z ^ 1], c);
            break;
        }
    }
}

void solve() {
    for (int i = 1; i <= max(m, n); ++i)
        p = max(p, max(sz(adj[0][i]), sz(adj[1][i])));
    while (!redges.empty()) {
        int i = redges.front();
        redges.pop();

        set<int> u[2];
        for (int z = 0; z < 2; ++z)
            for (int t : adj[z][edges[i][z]])
                if (col[t] > 0) u[z].insert(col[t]);

        int xc = -1;
        for (int tc = 1; tc <= p; ++tc) {
            bool chk = false;
            for (int z = 0; z < 2; ++z)
                chk |= u[z].find(tc) != u[z].end();
            if (!chk) { xc = tc; break; }
        }

        if (xc > 0)
            col[i] = xc;
        else {
            int cc[2] = {-1, -1};
            for (int z = 0; z < 2; ++z) {
                for (int t : adj[z][edges[i][z]]) {
                    int tc = col[t];
                    if (u[z ^ 1].find(tc) == u[z ^ 1].end()) {
                        cc[z] = tc;
                        break;
                    }
                }
            }
            col[i] = cc[0];
            fix(0, 0, edges[i][0], cc);
        }
    }
}

void print() {
    int k = 0;
    cout << p << "\n";
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << (ch[i][j] == '0' ? 0 : col[++k]) << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    enter();
    solve();
    print();
    return 0;
}