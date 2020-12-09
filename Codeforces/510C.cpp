#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()
#define fi first
#define se second

typedef pair<int, int> ii;

const int n_max = 1e5 + 5, chr_max = 26;

int n;
string s[n_max];
vector<int> a[chr_max];

// Topological sort
int deg_in[chr_max];
bool vis[chr_max];
priority_queue<ii, vector<ii>, greater<ii>> q;

char ans[chr_max];

inline int node_id(char x) { return x - 'a'; }

bool solve() {
    char cur = 'a';
    for (int i = 0; i < chr_max; ++i) q.push({deg_in[i], i});
    while (!q.empty()) {
        int u = q.top().se, x = q.top().fi; q.pop();
        if (vis[u]) continue;
        if (x > 0) return false;
        vis[u] = true;
        ans[u] = cur++;
        for (int v : a[u]) if (!vis[v]) {
            --deg_in[v];
            q.push({deg_in[v], v});
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 2; i <= n; ++i) {
        bool flag = false;
        for (int j = 0; j < min(sz(s[i - 1]), sz(s[i])); ++j) {
            if (s[i][j] == s[i - 1][j]) continue;
            a[node_id(s[i - 1][j])].push_back(node_id(s[i][j]));
            ++deg_in[node_id(s[i][j])];
            flag = true;
            break;
        }
        if (flag) continue;
        if (sz(s[i]) < sz(s[i - 1])) {
            cout << "Impossible\n";
            return 0;
        }
    }
    if (solve()) {
        for (int i = 0; i < chr_max; ++i)
            for (char j = 'a'; j <= 'z'; ++j)
                if (i == node_id(ans[node_id(j)])) {
                    cout << j;
                    break;
                }
        cout << "\n";
    } else cout << "Impossible\n";
    return 0;
}
