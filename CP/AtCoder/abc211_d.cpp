#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2, MOD = 1e9 + 7;

int n, m, d[N], f[N];
vector<int> a[N];
queue<int> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        // cerr << u << " " << v << endl;
    }
    memset(d, -1, sizeof(d));
    d[1] = 0;
    f[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        // cerr << u << endl;
        q.pop();
        for (int v : a[u]) {
            if (d[v] < 0) {
                f[v] = f[u];
                d[v] = d[u] + 1;
                q.push(v);
            } else if (d[v] == d[u] + 1) {
                (f[v] += f[u]) %= MOD;
            }
        }
    }
    cout << f[n];
    return 0;
}