#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 2;

int n, m, q;
ll in[N], out[N], ans;
vector<int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        // u < v
        ++in[u];
        ++out[v];
        a[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) ans += in[i] * out[i];
    cout << ans << "\n";
    cin >> q;
    while (q--) {
        int v;
        cin >> v;
        ans -= in[v] * out[v];
        for (int u : a[v]) {
            ans -= in[u] * out[u];
            ++in[u]; --in[v];
            --out[u]; ++out[v];
            ans += in[u] * out[u];
            a[u].push_back(v);
        }
        a[v].clear();
        cout << ans << "\n";
    }
    return 0;
}
