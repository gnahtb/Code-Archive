#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

#define sz(a) (int)a.size()

const int N_MAX = 2e5 + 5;

int n, k, c[N_MAX], l[N_MAX];
bool vis[N_MAX];
set<int> a[N_MAX];
vector<int> na[N_MAX];

priority_queue<ii, vector<ii>, greater<ii>> pq;
bool solve() {
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (sz(a[i]) == 1) pq.push({0, i});
    while (!pq.empty()) {
        int u = pq.top().second;
        l[u] = pq.top().first;
        pq.pop();
        if (l[u] > 0 && c[u] < 3) return false;
        cnt = max(cnt, l[u]);
        for (set<int>::iterator it = a[u].begin(); it != a[u].end(); ++it) {
            int v = *it;
            na[v].push_back(u);
            ++c[v];
            a[v].erase(a[v].find(u));
            if (sz(a[v]) == 1) {
                pq.push({l[u] + 1, v});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int p = -1;
        for (int v : na[i])
            if (p < 0) p = l[v];
            else if (p != l[v]) return false;
    }
    return cnt == k;
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("inp.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].insert(v);
        a[v].insert(u);
    }
    cout << (solve() ? "Yes\n" : "No\n");
    return 0;
}
