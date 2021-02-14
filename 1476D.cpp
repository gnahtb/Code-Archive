#include <bits/stdc++.h>

using namespace std;

int test;
int n;
string s;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> ans;

void bfs(int u) {
    queue<int> q;
    vector<int> comp;
    q.push(u);
    comp.push_back(u);
    vis[u] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) if (!vis[v]) {
            vis[v] = true;
            comp.push_back(v);
            q.push(v);
        }
    }
    for (int i : comp)
        if (i <= n) ans[i] = comp.size();
}

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> test;
    while (test--) {
        cin >> n >> s;
        adj.clear();
        vis.clear();
        ans.clear();
        adj.resize(n * 2 + 2);
        vis.resize(n * 2 + 2);
        ans.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                adj[i + 1].push_back(i + n + 1);
                adj[i + n + 1].push_back(i + 1);
            } else {
                adj[i].push_back(i + n + 2);
                adj[i + n + 2].push_back(i);
            }
        }
        for (int i = 0; i <= n; ++i)
            if (!vis[i]) bfs(i);
        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}