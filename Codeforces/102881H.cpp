#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 2;

int n, m;
ll s[N];
vector<pair<int, ll>> a[N];
bool crit[N];
int adj_crits[N];

int main() {
    ios::sync_with_stdio(false);
    freopen("hide.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (s[u] + w < s[v] || s[v] + w < s[u]) {
            cout << -1;
            return 0;
        }
        a[u].emplace_back(v, w);
        a[v].emplace_back(u, w);
    }
    int total_crit = 0;
    for (int u = 1; u <= n; ++u) {
        crit[u] = true;
        for (pair<int, ll> i : a[u]) if (s[u] == s[i.first] + i.second) crit[u] = false;
        total_crit += crit[u];
        if (crit[u]) {
            for (pair<int, ll> i : a[u]) {
                ++adj_crits[i.first];
            }
        }
    }
    for (int u = 1; u <= n; ++u) {
        if (adj_crits[u] == total_crit) {
            bool ok = true;
            for (pair<int, ll> i : a[u]) {
                if (crit[i.first]) {
                    if (i.second != s[i.first]) {
                        ok = false;
                        break;
                    }
                } else {
                    if (s[i.first] > i.second) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                cout << u;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}