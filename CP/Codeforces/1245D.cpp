#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2002;

int n;
int x[N], y[N], c[N], k[N];
vector<pair<ll, pii>> edges;

ll yen;
vector<int> v;
vector<pii> e;

int lab[N];

int GetRoot(int u) {
    return lab[u] < 0 ? u : lab[u] = GetRoot(lab[u]);
}

void Unite(int u, int v) {
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        edges.emplace_back(c[i], pii(0, i));
    }
    for (int i = 1; i <= n; ++i) cin >> k[i];
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            ll tmp = 1LL * (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
            edges.emplace_back(tmp, pii(i, j));
        }
    sort(edges.begin(), edges.end());
    memset(lab, -1, sizeof lab);
    for (int i = 0; i < sz(edges); ++i) {
        pii ei = edges[i].second;
        int s = GetRoot(ei.first);
        int t = GetRoot(ei.second);
        if (s == t) continue;
        yen += edges[i].first;
        if (ei.first == 0) {
            v.push_back(ei.second);
        } else {
            e.push_back(ei);
        }
        Unite(s, t);
    }
    cout << yen << "\n";
    cout << sz(v) << "\n";
    for (int i : v) cout << i << " ";
    cout << "\n" << sz(e) << "\n";
    for (pii i : e) cout << i.first << " " << i.second << "\n";
    return 0;
}
