#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

typedef long long ll;

const int N = 2e5 + 2;

int test, n, dif[N][2];
bool suit[N];
map<int, ll> f[N][2];
vector<int> adj[N];
ll ans;

void Reset() {
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        f[i][0].clear();
        f[i][1].clear();
        dif[i][0] = dif[i][1] = 0;
    }
}

void DFS(int u, int p) {
    map<int, ll> ftmp;
    ftmp.clear();
    for (int i = 0; i < sz(adj[u]); ++i) {
        int v = adj[u][i];
        if (v == p) continue;
        DFS(v, u);

        // update answer
        if (sz(f[u][1]) < sz(f[v][0])) {
            for (map<int, ll>::iterator it = f[u][1].begin(); it != f[u][1].end(); ++it) {
                int expe = it->first - dif[u][1] - dif[v][0];
                ans += it->second * f[v][0][expe];
            }
        } else {
            for (map<int, ll>::iterator it = f[v][0].begin(); it != f[v][0].end(); ++it) {
                int expe = it->first + dif[u][1] + dif[v][0];
                ans += it->second * f[u][1][expe];
            }
        }

        if (sz(f[v][1]) < sz(f[u][0])) {
            for (map<int, ll>::iterator it = f[v][1].begin(); it != f[v][1].end(); ++it) {
                int expe = it->first - dif[v][1] - dif[u][0];
                ans += it->second * f[u][0][expe];
            }
        } else {
            for (map<int, ll>::iterator it = f[u][0].begin(); it != f[u][0].end(); ++it) {
                int expe = it->first + dif[v][1] + dif[u][0];
                ans += it->second * f[v][1][expe];
            }
        }

        if (sz(ftmp) < sz(f[v][1])) {
            for (map<int, ll>::iterator it = ftmp.begin(); it != ftmp.end(); ++it) {
                int expe = it->first - dif[v][0];
                ans += it->second * f[v][0][expe];
            }
        } else {
            for (map<int, ll>::iterator it = f[v][0].begin(); it != f[v][0].end(); ++it) {
                int expe = it->first + dif[v][0];
                ans += it->second * ftmp[expe];
            }
        }

        // merge
        if (sz(f[u][0]) < sz(f[v][0])) {
            swap(f[u][0], f[v][0]);
            swap(dif[u][0], dif[v][0]);
        }
        for (map<int, ll>::iterator it = f[v][0].begin(); it != f[v][0].end(); ++it) {
            int expe1 = it->first + dif[v][0];
            int expe = expe1 - dif[u][0];
            ftmp[expe1] += f[u][0][expe] * it->second;
            f[u][0][expe] += it->second;
        }

        if (sz(f[u][1]) < sz(f[v][1])) {
            swap(f[u][1], f[v][1]);
            swap(dif[u][1], dif[v][1]);
        }
        for (map<int, ll>::iterator it = f[v][1].begin(); it != f[v][1].end(); ++it) {
            int expe = it->first - dif[v][1] + dif[u][1];
            f[u][1][expe] += it->second;
        }
    }
    for (auto it = ftmp.begin(); it != ftmp.end(); ++it) {
        f[u][1][it->first + dif[u][1]] += it->second;
    }
    if (suit[u]) {
        int expe = dif[u][1];
        ans += f[u][1][expe];
        ++f[u][0][-dif[u][0]];
    }
    ++dif[u][0];
    ++dif[u][1];
    // cerr << u << " " << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> test;
    while (test--) {
        Reset();
        cin >> n;
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) cin >> suit[i];
        DFS(1, 0);
        cout << (ans * 6) << "\n";
    }
    return 0;
}