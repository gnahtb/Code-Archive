#include <bits/stdc++.h>

using namespace std;

const int N = 1002;
const int pcnt = 2, p[pcnt] = {2, 5};
const int oo = 2e9;

int n, a[N][N], f[N][N][2], w[N][N][2];
bool zero;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                zero = true;
                f[i][j][0] = f[i][j][1] = oo;
                continue;
            }
            for (int k = 0; k < 2; ++k) {
                while (a[i][j] % p[k] == 0) {
                    ++w[i][j][k];
                    a[i][j] /= p[k];
                }
                int pre = i == 1 && j == 1 ? 0 : oo;
                if (i > 1) pre = min(pre, f[i - 1][j][k]);
                if (j > 1) pre = min(pre, f[i][j - 1][k]);
                f[i][j][k] = pre < oo ? w[i][j][k] + pre : oo;
            }
        }
    if (zero && min(f[n][n][0], f[n][n][1]) > 1) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] == 0) {
                    cout << "1\n";
                    for (int k = 1; k < i; ++k) cout << "D";
                    for (int k = 1; k < j; ++k) cout << "R";
                    for (int k = i; k < n; ++k) cout << "D";
                    for (int k = j; k < n; ++k) cout << "R";
                    return 0;
                }
            }
    } else {
        int k = f[n][n][0] < f[n][n][1] ? 0 : 1;
        cout << f[n][n][k] << "\n";
        string path = "";
        int i = n, j = n;
        while (i > 1 || j > 1) {
            if (i > 1 && f[i - 1][j][k] + w[i][j][k] == f[i][j][k]) {
                --i;
                path += "D";
            } else {
                --j;
                path += "R";
            }
        }
        reverse(path.begin(), path.end());
        cout << path;
    }
    return 0;
}
