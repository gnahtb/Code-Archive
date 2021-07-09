#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int n, m, tin[N];
bool used[N];
vector<int> adj[N];
vector<pair<pair<int, int>, int>> ans;

pair<pair<int, int>, int> CreateTriplet(pair<int, int> x, pair<int, int> y) {
    if (x.first == y.first) {
        return make_pair(make_pair(x.second, x.first), y.second);
    } else if (x.first == y.second) {
        return make_pair(make_pair(x.second, x.first), y.first);
    } else if (x.second == y.first) {
        return make_pair(make_pair(x.first, x.second), y.second);
    } else {
        return make_pair(make_pair(x.first, x.second), y.first);
    }
}

int tmr;
bool DFS(int u, int p) {
    used[u] = true;
    tin[u] = ++tmr;
    pair<int, int> pre(-1, -1);
    for (int v : adj[u]) if (v != p) {
        if (used[v] && tin[u] > tin[v]) {
            if (pre.first < 0) {
                pre = make_pair(u, v);
            } else {
                ans.push_back(CreateTriplet(pre, make_pair(u, v)));
                pre = make_pair(-1, -1);
            }
        } else if (!used[v]) {
            if (DFS(v, u)) {
                if (pre.first < 0) {
                    pre = make_pair(u, v);
                } else {
                    ans.push_back(CreateTriplet(pre, make_pair(u, v)));
                    pre = make_pair(-1, -1);
                }
            }
        }
    }
    if (pre.first < 0) return true;
    else {
        if (p == 0) return true;
        ans.push_back(CreateTriplet(pre, make_pair(u, p)));
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        if (!used[i]) DFS(i, 0);
    cout << ans.size() << "\n";
    for (pair<pair<int, int>, int> i : ans) {
        cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
    }
    return 0;
}
