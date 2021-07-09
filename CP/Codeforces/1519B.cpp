#include <bits/stdc++.h>

using namespace std;

int n, m, k, fmi[102][102], fmx[102][102];

bool valid_cell(int i, int j) {
    return 0 < i && i <= n && 0 < j && j <= m;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                fmi[i][j] = INT_MAX;
                fmx[i][j] = -1;
            }
        fmi[1][1] = fmx[1][1] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                fmi[i + 1][j] = min(fmi[i + 1][j], fmi[i][j] + j);
                fmi[i][j + 1] = min(fmi[i][j + 1], fmi[i][j] + i);
                fmx[i + 1][j] = max(fmx[i + 1][j], fmi[i][j] + j);
                fmx[i][j + 1] = max(fmx[i][j + 1], fmi[i][j] + i);
            }
        }
        if (fmi[n][m] <= k && k <= fmx[n][m]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}