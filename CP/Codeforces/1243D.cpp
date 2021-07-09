#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n, m;
set<int> a[N];
vector<pair<int, int>> e;

int lab[N];

set<int> rem;
queue<int> q;
int bfs(int x) {
    rem.erase(rem.find(x));
    int ret = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        lab[u] = x;
        ++ret;
        int pre = 0;
        for (int v : a[u]) {
            auto it = rem.upper_bound(pre);
            auto it1 = rem.lower_bound(v);
            --it1;
            if (*it <= *it1) {
                ++it1;
                vector<int> tmp;
                tmp.clear();
                for (; it != it1; ++it) {
                    q.push(*it);
                    tmp.push_back(*it);
                }
                for (int i : tmp)
                    rem.erase(rem.find(i));
            }
            pre = v;
        }
    }
    return ret;
}

int Root(int u) {
    return lab[u] < 0 ? u : lab[u] = Root(lab[u]);
}

void Unite(int u, int v) {
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].insert(v);
        a[v].insert(u);
        e.emplace_back(u, v);
    }
    for (int i = 0; i <= n; ++i) {
        rem.insert(i);
        a[i].insert(n + 1);
    }
    for (int i = 1; i <= n; ++i) {
        if (rem.find(i) != rem.end()) {
            q.push(i);
            int cnt = bfs(i);
            lab[i] = -cnt;
        }
    }
    int ans = 0;
    for (auto i : e) {
        int u = Root(i.first), v = Root(i.second);
        if (u == v) continue;
        ++ans;
        Unite(u, v);
    }
    cout << ans << "\n";
    return 0;
}
