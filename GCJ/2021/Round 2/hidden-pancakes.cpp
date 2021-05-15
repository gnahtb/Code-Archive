#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7, LIM = 1e6;

int test, n, v[LIM], in_deg[LIM];
vector<int> adj[LIM];
bool vis[LIM];
ll ans;

void foo(int u) {
    if (u > n) ++ans;
    for (int i = 1; i <= n; i++)
        if (!vis[i] && !in_deg[i]) {
            vis[i] = true;
            for (int j : adj[i]) --in_deg[j];
            foo(u + 1);
            for (int j : adj[i]) ++in_deg[j];
            vis[i] = false;
        }
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        in_deg[i] = 0;
    }	
    stack<int> st;
    while (!st.empty()) st.pop();
    for (int i = 1; i <= n; ++i) cin >> v[i];
    if (v[1] != 1) return;
    for (int i = 1; i < n; ++i) if (v[i] + 2 <= v[i + 1]) return;
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            if (v[i] > v[i - 1]) {
                adj[i - 1].push_back(i);
                ++in_deg[i];
            } else {
                for (int j = 1; j <= v[i - 1] - v[i] + 1; ++j) {
                    adj[i].push_back(st.top());
                    ++in_deg[st.top()];
                    st.pop();
                }
                vector<int> tmp;
                tmp.clear();
                while (!st.empty()) {
                    adj[st.top()].push_back(i);
                    ++in_deg[i];
                    tmp.push_back(st.top());
                    st.pop();
                }
                for (int i = sz(tmp) - 1; i >= 0; --i) st.push(tmp[i]);
            }	
        }
        st.push(i);
    }
    foo(1);
}

int main() {
    cin >> test;
    for (int itest = 1; itest <= test; ++itest) {
        cin >> n;
        ans = 0;
        solve();
        ans %= MOD;
        cout << "Case #" << itest << ": " << ans << endl;
    }
}