#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;

int t;
int n, m;
vector<int> a1[N], a2[N];
bool used[N];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        for (int i = 1; i <= n; ++i) {
            a1[i].clear();
            a2[i].clear();
        }

        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            a1[u].push_back(v);
            a2[v].push_back(u);
        }

        // take the first resident
        fill(used + 1, used + n + 1, false);
        q.push(1);
        used[1] = true;
        int res = 1, cat = n - 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : a1[u]) {
                if (used[v]) continue;
                ++res;
                --cat;
                used[v] = true;
                q.push(v);
            }
        }
        if (res > 0 && cat > 0) {
            cout << "Yes\n" << res << " " << cat << "\n";
            for (int i = 1; i <= n; ++i)
                if (used[i]) cout << i << " ";
            cout << "\n";
            for (int i = 1; i <= n; ++i)
                if (!used[i]) cout << i << " ";
            cout << "\n";
            continue;
        }

        // take the first cat
        fill(used + 1, used + n + 1, false);
        q.push(1);
        used[1] = true;
        res = n - 1, cat = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : a2[u]) {
                if (used[v]) continue;
                ++cat;
                --res;
                used[v] = true;
                q.push(v);
            }
        }
        if (res > 0 && cat > 0) {
            cout << "Yes\n" << res << " " << cat << "\n";
            for (int i = 1; i <= n; ++i)
                if (!used[i]) cout << i << " ";
            cout << "\n";
            for (int i = 1; i <= n; ++i)
                if (used[i]) cout << i << " ";
            cout << "\n";
            continue;
        }

        cout << "No\n";
    }
    return 0;
}
