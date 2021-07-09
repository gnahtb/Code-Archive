#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(a) (int)(a).size()
#define fi first
#define se second

const int N_MAX = 1E5 + 5;

int n, c[N_MAX], cur[N_MAX];
ll ans[N_MAX];
map<int, int> *cnt[N_MAX];
vector<int> a[N_MAX];

inline void update(int node, int value, int color) {
    if (value > cur[node])
        cur[node] = value, ans[node] = color;
    else if (value == cur[node]) ans[node] += color;
}

void dfs(int u, int p) {
    bool is_leaf = true;
    cnt[u] = nullptr;
    for (int v : a[u]) if (v != p) {
        is_leaf = false;
        dfs(v, u);
        if (cnt[u] == nullptr || sz(*cnt[u]) < sz(*cnt[v])) {
            swap(cnt[u], cnt[v]);
            ans[u] = ans[v];
            cur[u] = cur[v];
        }
        if (cnt[v] == nullptr) continue;
        for (map<int, int>::iterator i = (*cnt[v]).begin(); i != (*cnt[v]).end(); ++i) {
            (*cnt[u])[(*i).fi] += (*i).se;
            update(u, (*cnt[u])[(*i).fi], (*i).fi);
        }
        delete(cnt[v]);
    }
    if (is_leaf) {
        cnt[u] = new map<int, int>();
        ++(*cnt[u])[c[u]];
        cur[u] = 1;
        ans[u] = c[u];
    } else update(u, ++(*cnt[u])[c[u]], c[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    return 0;
}
