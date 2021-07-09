#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define sz(a) (int)a.size()
#define fi first
#define se second

typedef pair<int, int> ii;

const int N = 1E5 + 5;

int n, k, p[N], d[N], f[N], s[N], ans = INT_MAX;
bool avail[N];
vector<int> lp;
vector<ii> a[N];
priority_queue<ii, vector<ii>> h;

int farthestNode(int u, int x) {
    int r = u;
    if (!x) d[u] = p[u] = 0;
    for (ii e : a[u]) {
        int v = e.fi, w = e.se;
        if (v == x) continue;
        d[v] = d[u] + w;
        p[v] = u;
        int t = farthestNode(v, u);
        r = d[t] > d[r] ? t : r;
    }
    return r;
}

void findLongestPath(vector<int> &x) {
    int u = farthestNode(farthestNode(1, 0), 0);
    while (u > 0) x.push_back(u), u = p[u];
}

int longestDistance(int u, int x) {
    int r = d[u];
    for (ii e : a[u]) {
        int v = e.fi, w = e.se;
        if (v == x) continue;
        d[v] = d[u] + w;
        r = max(r, longestDistance(v, u));
    }
    return r;
}

void calc(int u, int x) {
    for (ii e : a[u]) {
        int v = e.fi, w = e.se;
        if (!avail[v] && v != x) d[v] = d[u] + w, calc(v, u);
    }
}

void prep() {
    fill(f, f + N, 0);
    fill(d, d + N, 0);
    fill(avail, avail + N, true);
    for (int u : lp) avail[u] = false;
    for (int u : lp) for (ii e : a[u]) {
        if (!avail[e.fi]) continue;
        d[e.fi] = e.se;
        f[u] = max(f[u], longestDistance(e.fi, u));
    }
}

void solve() {
    if (sz(lp) <= k) {
        ans = 0;
        for (int u : lp) ans = max(ans, f[u]);
        return;
    }
    for (int i = 1; i < k - 2; ++i) h.push({f[lp[i]], i});
    for (int l = 0, r = k - 1; r < sz(lp); ++l, ++r) {
        if (r) h.push({f[lp[r - 1]], r - 1});
        while (!h.empty() && h.top().se <= l) h.pop();
        int cur = max(d[lp[l]], d[lp.back()] - d[lp[r]]);
        if (!h.empty()) cur = max(cur, h.top().fi);
        ans = min(ans, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w}); a[v].push_back({u, w});
    }
    findLongestPath(lp);
    prep();
    calc(lp[0], 0);
    solve();
    cout << ans << "\n";
    // for (int i : lp) cout << i << " " << d[i] << "\n";
    return 0;
}
