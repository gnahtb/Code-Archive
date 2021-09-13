#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
const int MOD = 998244353;

int test, n, f[N];
vector<int> a[N];

pair<bool, bool> dfs(int u, int p, int k) {
    int cnt = 0;
    for (int v : a[u]) if (v != p) {
        pair<bool, bool> t = dfs(v, u, k);
        if (!t.first) return make_pair(false, false);
        cnt += t.second;
    }
    if (p == 0) {
        if (cnt % k == 0) return make_pair(true, true);
        else return make_pair(false, false);
    } else {
        if (cnt % k == 0) return make_pair(true, true);
        else if ((cnt + 1) % k == 0) return make_pair(true, false);
        else return make_pair(false, false);
    }
}

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) f[i] = 0, a[i].clear();
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        f[1] = 1;
        for (int i = 1; i < n; ++i) (f[1] *= 2) %= MOD;
        for (int i = 2; i <= n - 1; ++i)
            if ((n - 1) % i == 0) {
                f[i] = dfs(1, 0, i).first;
            }
        for (int i = n; i; --i) {
            for (int j = i * 2; j <= n; j += i) {
                (f[i] += MOD - f[j]) %= MOD;
            }
        }
        for (int i = 1; i <= n; ++i) cout << f[i] << " ";
        cout << endl;
    }
    return 0;
}