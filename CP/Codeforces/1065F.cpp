#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

const int N_MAX = 1e6 + 5;

int n, k, ans = 1;
vector<int> a[N_MAX];

// 0 -> can go back
// 1 -> cannot go back
int f[N_MAX][2];
set<int, greater<int>> l[N_MAX];
void dfs1(int u, int h) {
    if (a[u].empty()) {
        f[u][0] = f[u][1] = 1;
        l[u].insert(h);
        return;
    }
    // int tmp = 0;
    for (int v : a[u]) {
        dfs1(v, h + 1);
        // for (int i = tin[v]; i <= tout[v]; ++i)
        //     if (sz(a[tour[i]]) == 0 && h[tour[i]] - h[u] <= k) ++ch[v];
        // ch[v] /= 2;
        while (!l[v].empty() && *(l[v].begin()) - h > k)
            l[v].erase(l[v].begin());
        if (!l[v].empty())
            f[u][0] += f[v][0];
    }
    for (int v : a[u]) {
        int temp = f[u][0];
        if (!l[v].empty())
            temp -= f[v][0];
        f[u][1] = max(f[u][1], temp + f[v][1]);
    }
    for (int v : a[u]) {
        if (sz(l[u]) < sz(l[v]))
            swap(l[u], l[v]);
        for (auto it = l[v].begin(); it != l[v].end(); ++it)
            l[u].insert(*it);
        l[v].clear();
    }
    ans = max(ans, f[u][1]);
    // f[u] += tmp;
    // ans = max(ans, f[u][0]);
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("inp.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        a[p].push_back(i);
    }
    dfs1(1, 0);
    cout << ans << "\n";
    return 0;
}
