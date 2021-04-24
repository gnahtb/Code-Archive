#include <bits/stdc++.h>

using namespace std;

const int N = 502;
const int DI[4] = {-1, 0, 1, 0};
const int DJ[4] = {0, 1, 0, -1};

int n, m, k, d[N][N][4], fd[N][N][12];
bool vis[N][N];

bool valid_cell(int i, int j) {
    return 0 < i && i <= n && 0 < j && j <= m;
}

int manh(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    // freopen("inp.txt", "r", stdin);
    cin >> n >> m >> k;
    if (k % 2 != 0) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) cout << "-1 ";
            cout << "\n";
        }
        return 0;
    }
    k /= 2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < m; ++j) {
            cin >> d[i][j][1];
            d[i][j + 1][3] = d[i][j][1];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> d[i][j][2];
            d[i + 1][j][0] = d[i][j][2];
        }
    }
    memset(fd, 0, sizeof(fd));
    for (int tk = 1; tk <= k; ++tk) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                fd[i][j][tk] = INT_MAX;
                for (int t = 0; t < 4; ++t) if (valid_cell(i + DI[t], j + DJ[t])) {
                    fd[i][j][tk] = min(fd[i][j][tk], fd[i + DI[t]][j + DJ[t]][tk - 1] + d[i][j][t]);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << (fd[i][j][k] * 2) << " ";
        }
        cout << "\n";
    }
    return 0;
}