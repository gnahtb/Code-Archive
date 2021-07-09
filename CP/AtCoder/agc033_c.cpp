#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<bool> f;
vector<vector<int>> a;

int lp(int u = 1, int p = 0) {
    int mx = 0, mx1 = 0;
    for (int v : a[u]) if (v != p) {
        int t = lp(v, u);
        if (t > mx) {
            mx1 = mx;
            mx = t;
        } else if (t > mx1) mx1 = t;
    }
    m = max(m, mx + mx1 + 1);
    return mx + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    a.resize(n + 2);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    lp();
    f.resize(m + 2);
    f[1] = true;
    f[2] = false;
    for (int i = 3; i <= m; ++i)
        if (f[i - 1] && f[i - 2]) f[i] = false;
        else f[i] = true;
    cout << (f[m] ? "First\n" : "Second\n");
    return 0;
}