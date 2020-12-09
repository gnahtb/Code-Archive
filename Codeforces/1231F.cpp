#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 7002;

int n, d[N];
ll a[N], b[N];
bool used[N], adj[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (a[i] > (a[i] & a[j])) {
                ++d[i];
                adj[j][i] = true;
            }
        }
    int cur = n;
    while (true) {
        vector<int> v;
        v.clear();
        for (int i = 1; i <= n; ++i)
            if (!used[i] && d[i] + 1 == cur)
                v.push_back(i);
        if (v.empty()) break;
        for (int u : v) {
            used[u] = true;
            --cur;
            for (int i = 1; i <= n; ++i)
                if (adj[u][i]) --d[i];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) if (!used[i]) ans += b[i];
    cout << ans << "\n";
    return 0;
}
