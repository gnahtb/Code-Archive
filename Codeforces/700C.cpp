#include <bits/stdc++.h>

#define sz(a) (int)a.size()
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

struct Edge {
    int u, v, w;
    Edge() { u = v = w = 0; }
};

istream& operator>>(istream& in, Edge& e) {
    in >> e.u >> e.v >> e.w;
    return in;
}

const int N = 1002;
const int M = 30002;
const int oo = INT_MAX;

int n, m, s, t;
Edge e[M];
vector<pii> a[N];
vector<int> p1, p2;

bool flag[M], used[M], cut[M];
int tin[N], fup[N], tmr;

int bud = oo;
vector<int> ans;

void Tarjan(int u = s) {
    tin[u] = fup[u] = ++tmr;
    for (int it = 0; it < sz(a[u]); ++it) {
        int v = a[u][it].fi;
        int i = a[u][it].se;
        if (used[i] || !flag[i]) continue;
        used[i] = true;
        if (tin[v] == 0) {
            Tarjan(v);
            fup[u] = min(fup[u], fup[v]);
            if (fup[v] > tin[u]) cut[i] = true;
        } else {
            fup[u] = min(fup[u], tin[v]);
        }
    }
}

int pre[N];

void Path(int u = s) {
    for (int it = 0; it < sz(a[u]); ++it) {
        int v = a[u][it].fi;
        int i = a[u][it].se;
        if (pre[v] >= 0 || !flag[i]) continue;
        pre[v] = u;
        Path(v);
    }
}

void Trace(vector<int>& path, int u = t) {
    path.clear();
    while (pre[u] > 0) {
        for (int it = 0; it < sz(a[u]); ++it) {
            int v = a[u][it].fi;
            int i = a[u][it].se;
            if (!flag[i]) continue;
            if (v == pre[u]) {
                path.push_back(i);
                break;
            }
        }
        u = pre[u];
    }
}

void Reset() {
    fill(cut + 1, cut + m + 1, false);
    fill(used + 1, used + m + 1, false);
    fill(tin + 1, tin + n + 1, 0);
    fill(fup + 1, fup + n + 1, 0);
    fill(pre + 1, pre + n + 1, -1);
    pre[s] = 0;
    tmr = 0;
}

void Print() {
    if (bud == oo) {
        cout << "-1\n";
        return;
    }
    cout << bud << "\n" << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i) {
        cin >> e[i];
        a[e[i].u].emplace_back(e[i].v, i);
        a[e[i].v].emplace_back(e[i].u, i);
    }
    fill(flag + 1, flag + m + 1, true);
    Reset();
    Path();
    if (pre[t] < 0) {
        cout << "0\n0\n";
        return 0;
    }
    Trace(p1);
    for (int i : p1) {
        flag[i] = false;
        Reset();
        Tarjan();
        Path();
        if (pre[t] < 0) {
            if (bud > e[i].w) {
                bud = e[i].w;
                ans.clear();
                ans.push_back(i);
            }
        } else {
            Trace(p2);
            for (int j : p2) if (cut[j]) {
                if (bud > e[i].w + e[j].w) {
                    bud = e[i].w + e[j].w;
                    ans.clear();
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        flag[i] = true;
    }
    Print();
    return 0;
}
