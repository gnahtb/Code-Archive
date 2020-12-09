#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int n, a[N];
bool vis[N];
set<int> ad[N];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        ad[u].insert(v);
        ad[v].insert(u);
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];

    if (a[1] != 1) {
        cout << "No\n";
        return 0;
    }

    int i = 1, j = 2;
    vis[a[1]] = true;
    while (i <= n) {
        int u = a[i++];
        int cnt = 0;
        for (int v : ad[u])
            if (!vis[v]) ++cnt;
        while (j <= n) {
            set<int>::iterator it = ad[u].find(a[j]);
            if (it == ad[u].end()) break;
            vis[a[j++]] = true;
            --cnt;
        }
        if (cnt != 0) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}
