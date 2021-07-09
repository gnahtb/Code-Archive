#include <bits/stdc++.h>

using namespace std;

const int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m;
char dest[1005][1005], cur[1005][1005];
string ans = "YES";

bool check(int i, int j) {
    for (int k = 0; k < 8; ++k)
        if (dest[i + di[k]][j + dj[k]] == '.') return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> dest[i][j];
            cur[i][j] = '.';
        }
    for (int i = 2; i < n; ++i)
        for (int j = 2; j < m; ++j) if (check(i, j))
            for (int k = 0; k < 8; ++k) cur[i + di[k]][j + dj[k]] = '#';
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (dest[i][j] != cur[i][j]) ans = "NO";
    cout << ans << "\n";
    return 0;
}
