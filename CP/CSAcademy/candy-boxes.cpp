#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;

const int N = 1E5 + 5;

int n, m, a[N];
queue<ii> p;
queue<int> q;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x;
        if (x == 1) {
            int y;
            cin >> y;
            if (--a[y] < 0) p.push({y, i});
        } else q.push(i);
    }
    while (!q.empty()) {
        int c = q.front(); q.pop();
        if (!p.empty()) {
            ii d = p.front(); p.pop();
            if (d.se < c) { cout << "IMPOSSIBLE\n"; return 0; }
            ans.push_back(d.fi);
        } else ans.push_back(1);
    }
    if (!p.empty()) { cout << "IMPOSSIBLE\n"; return 0; }
    for (int i : ans) cout << i << "\n";
    return 0;
}