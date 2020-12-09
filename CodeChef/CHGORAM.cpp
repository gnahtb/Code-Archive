#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct FenwickTree {
    int n;
    vector<int> a;

    void build(int _n) {
        a.clear();
        n = _n;
        a.assign(n + 2, 0);
    }

    void inc(int i, int x) {
        for (; i <= n; i += i & -i) a[i] += x;
    }

    int sum(int i) {
        int ret = 0;
        for (; i; i -= i & -i) ret += a[i];
        return ret;
    }
} fen;

int t;
int n, pe[3], tmr;
vector<vector<int>> adj;
vector<int> small, big;
ll ans;

void enter() {
    cin >> n;
    cin >> pe[0] >> pe[1] >> pe[2];
    fen.build(n);
    adj.resize(n + 2);
    small.resize(n + 2);
    big.resize(n + 2);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u = 1, int p = 0) {
    small[u] = fen.sum(p);
    big[u] = tmr++;
    for (int v : adj[u]) if (v != p) dfs(v, u);
    fen.inc(u, 1);
    small[u] = fen.sum(p) - small[u];
    big[u] = (++tmr - big[u]) / 2 - small[u];
}

void calc(ll id, ll big, ll small, ll& sum) {
    switch (pe[1]) {
    case 1:
        sum += big * (n - id - big);
        break;
    case 2:
        sum += small * (n - id - big) + big * (id - 1 - small);
        break;
    case 3:
        sum += small * (id - 1 - small);
        break;
    }
}

void dfs1(int u = 1, int p = 0) {
    int psmall = u - 1, pbig = n - u;
    for (int v : adj[u]) if (v != p) {
        psmall -= small[v];
        pbig -= big[v];
    }
    ll sum = 0;
    for (int v : adj[u])
        if (v == p) {
            calc(u, pbig, psmall, sum);
        } else {
            calc(u, big[v], small[v], sum);
            dfs1(v, u);
        }
    ans += sum;
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("inp.txt", "r", stdin);

    cin >> t;
    while (t--) {
        adj.clear();
        enter();
        tmr = ans = 0;
        dfs();
        // for (int i = 1; i <= n; ++i) {
        //     cout << i << "------\n";
        //     cout << big[i] << " " << small[i] << "\n";
        // }
        dfs1();
        cout << (ans / 2) << "\n";
    }

    return 0;
}