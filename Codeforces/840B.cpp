#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 2;

int n, m, d[N];
bool used[N];
vector<pair<int, int>> a[N];
vector<int> ans;

bool DFS(int u) {
    used[u] = true;
    bool flag = d[u] == 1;
    for (pair<int, int> i : a[u]) {
        int v = i.first;
        if (used[v]) continue;
        bool tmp = DFS(v);
        if (tmp) {
            ans.push_back(i.second);
            flag ^= 1;
        }
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int odd = 0, unknown = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        if (d[i] == 1) ++odd;
        if (d[i] == -1) ++unknown;
    }
    if (odd % 2 != 0) {
        if (unknown == 0) {
            cout << "-1\n";
            return 0;
        } else {
            for (int i = 1; i <= n; ++i)
                if (d[i] == -1) {
                    d[i] = 1;
                    break;
                }
        }
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].emplace_back(v, i);
        a[v].emplace_back(u, i);
    }
    DFS(1);
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << "\n";
    return 0;
}
