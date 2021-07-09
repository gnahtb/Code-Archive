#include <bits/stdc++.h>

using namespace std;

int test, n, m, b[102][102], ans[102][102];
vector<pair<int, int>> l;

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> test;
    while (test--) {
        l.clear();
        cin >> n >> m;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) ans[i][j] = -1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                cin >> b[i][j];
                l.emplace_back(i, j);
            }
        sort(l.begin(), l.end(), [](pair<int, int> lhs, pair<int, int> rhs) {
            return b[lhs.first][lhs.second] < b[rhs.first][rhs.second];
        });
        for (int i = 0; i < m; ++i) {
            ans[i + 1][l[i].first] = b[l[i].first][l[i].second];
        }
        for (int i = m; i < (int)l.size(); ++i) {
            for (int j = 1; j <= m; ++j)
                if (ans[j][l[i].first] < 1) {
                    ans[j][l[i].first] = b[l[i].first][l[i].second];
                    break;
                }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) cout << ans[j][i] << " ";
            cout << "\n";
        }
    }
    return 0;
}