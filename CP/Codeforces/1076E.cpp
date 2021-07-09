#include <bits/stdc++.h>

using namespace std;

#define long long long
#define fi first
#define se second

typedef pair<int, int> ii;

const int N_MAX = 3E5 + 5;

int n, m;
long sum[N_MAX], ans[N_MAX];
vector<int> a[N_MAX];
vector<ii> q[N_MAX];

void dfs(int u, int p, int d) {
//    cout << cur << "\n";
    for (ii i : q[u]) {
        sum[d] += i.se;
        sum[min(d + i.fi + 1, n + 3)] -= i.se;
    }
    ans[u] += sum[d];
    for (int v : a[u]) if (v != p) {
        ans[v] = ans[u];
        dfs(v, u, d + 1);
    }
    for (ii i : q[u]) {
        sum[d] -= i.se;
        sum[min(d + i.fi + 1, n + 3)] += i.se;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int v, d, x;
        cin >> v >> d >> x;
        q[v].push_back({d, x});
//        cout << v << " " << d << " " << x << "\n";
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    return 0;
}
