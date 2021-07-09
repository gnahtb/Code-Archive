#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 2;

int n, m, x, y, lab[N], tin[N], fup[N];
vector<int> a[N], aa[N];
ll ans;
int comp;
vector<int> nodes[N];
bool used[N];

int tmr = 0;
stack<int> st;
void DFS(int u, ll& tmp, int& compo) {
    tin[u] = fup[u] = ++tmr;
    st.push(u);
    for (int v : a[u]) {
        if (tin[v] == 0) {
            DFS(v, tmp, compo);
            fup[u] = min(fup[u], fup[v]);
        } else {
            fup[u] = min(fup[u], tin[v]);
        }
    }
    if (tin[u] == fup[u]) {
        ++compo;
        int cnt = 0;
        while (true) {
            int t = st.top();
            st.pop();
            ++cnt;
            lab[t] = compo;
            tin[t] = fup[t] = INT_MAX;
            if (u == t) break;
        }
        tmp += min(1LL * (cnt - 1) * y, 1LL * cnt * x);
    }
}

int DFS1(int u, vector<int>& vt) {
    used[u] = true;
    vt.push_back(u);
    int ret = 1;
    for (int v : aa[u]) {
        if (!used[v]) ret += DFS1(v, vt);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        aa[u].push_back(v);
        aa[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) if (!used[i]) {
        ++comp;
        int compo = 0;
        int tmp = DFS1(i, nodes[comp]);
        ll tmp1 = 0;
        for (int u : nodes[comp]) if (tin[u] == 0) DFS(u, tmp1, compo);
        tmp1 += 1LL * min(x, y) * (compo - 1);
        ll tmp2 = min(1LL * y * (tmp - 1), 1LL * x * tmp);
        ans += min(tmp1, tmp2);
    }
    cout << ans << "\n";
    return 0;
}