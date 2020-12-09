#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 102, C = 26;

int n, m, d[N * N];
vector<pii> a[N], raa[N * N];

inline int encode(int x, int y) {
    return (x - 1) * n + y;
}

inline void decode(int v, int& x, int& y) {
    x = (v - 1) / n + 1;
    y = v - (x - 1) * n;
}

void build() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int cur = encode(i, j);
            for (pii t : a[i]) {
                int nxt = encode(t.first, j);
                // aa[cur].emplace_back(nxt, t.second);
                raa[nxt].emplace_back(cur, t.second);
                ++d[cur];
            }
            for (pii t : a[j]) {
                int nxt = encode(i, t.first);
                // aa[cur].emplace_back(nxt, t.second);
                raa[nxt].emplace_back(cur, t.second);
                ++d[cur];
            }
        }
}

bool f[N * N][2][C];
queue<int> q;
void solve() {
    for (int i = 1; i <= n * n; ++i)
        if (d[i] == 0) {
            q.push(i);
        }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int i, j;
        decode(u, i, j);
        for (pii t : a[i]) {
            int nxt = encode(t.first, j);
            for (int k = 0; k < C; ++k)
                if (t.second >= k)
                    f[u][0][k] |= (f[nxt][1][t.second] ^ 1);
        }
        for (pii t : a[j]) {
            int nxt = encode(i, t.first);
            for (int k = 0; k < C; ++k)
                if (t.second >= k)
                    f[u][1][k] |= (f[nxt][0][t.second] ^ 1);
        }
        for (pii t : raa[u]) {
            if ((--d[t.first]) == 0) {
                q.push(t.first);
            }
        }
        for (int k = C - 2; k >= 0; --k) {
            f[u][0][k] |= f[u][0][k + 1];
            f[u][1][k] |= f[u][1][k + 1];
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        a[u].emplace_back(v, c - 'a');
    }
    build();
    solve();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int u = encode(i, j);
            if (f[u][0][0]) cout << "A";
            else cout << "B";
        }
        cout << "\n";
    }
    return 0;
}
