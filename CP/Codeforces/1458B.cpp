#include <bits/stdc++.h>

using namespace std;

const int N = 102;

int n, a[N], b[N], f[N][N][N * N];

inline void Opt(int& x, int y) {
    if (x < y) x = y;
}

int main() {
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        s += b[i];
    }
    memset(f, -1, sizeof(f));
    f[0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= s; ++k) {
                f[i][j][k] = f[i - 1][j][k];
                if (k >= b[i] && j > 0 && f[i - 1][j - 1][k - b[i]] >= 0)
                    Opt(f[i][j][k], f[i - 1][j - 1][k - b[i]] + a[i]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        for (int j = 0; j <= s; ++j) {
            if (f[n][i][j] >= 0)
                ans = max(ans, j * 2 + min(s - j, (f[n][i][j] - j) * 2));
        }
        cout << (ans / 2);
        if (ans % 2 != 0) cout << ".5";
        cout << " ";
    }
    return 0;
}