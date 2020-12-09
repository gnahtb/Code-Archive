#include <bits/stdc++.h>

using namespace std;

int n, m, x[10], chk[10];
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < m; ++i) {
        int y;
        cin >> y;
        chk[y] = true;
    }
    for (int i = 0; i < n; ++i) if (chk[x[i]]) ans.push_back(x[i]);

    for (int i : ans) cout << i << " ";

    return 0;
}
