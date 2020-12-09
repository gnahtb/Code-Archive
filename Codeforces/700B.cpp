#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 2e5 + 5;

int n, k;
long long ans = 0;
bool flag[N_MAX];
vector<int> a[N_MAX];

int dfs(int u, int p) {
    int cnt = flag[u];
    for (int v : a[u]) if (v != p) {
        int cur = dfs(v, u);
        cnt += cur;
        ans += min(k + k - cur, cur);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= k + k; ++i) {
        int u;
        cin >> u;
        flag[u] = true;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        if (flag[i]) { dfs(i, 0); break; }
    cout << ans << "\n";
    return 0;
}
