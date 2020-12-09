#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1002;
 
int n, x, k;
int s[N][4], f[3][N][52][52];
 
inline void opt(int &a, int b) {
    if (a < b) a = b;
}
 
int main() {
    ios::sync_with_stdio(false);
 
    cin >> n >> x >> k;
    int r;
    cin >> r;
    for (int i = 1, a; i <= r; ++i) {
        cin >> a;
        s[a][0] = 1;
    }
    cin >> r;
    for (int i = 1, a; i <= r; ++i) {
        cin >> a;
        s[a][1] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        s[i][2] = s[i - 1][2] + max(s[i][0], s[i][1]);
        s[i][3] = s[i - 1][3] + min(s[i][0], s[i][1]);
        s[i][0] += s[i - 1][0];
        s[i][1] += s[i - 1][1];
    }
 
    int t = n / k;
    if (n % k > 0) ++t;
 
    if (t * 2 <= x) {
        cout << s[n][2] << "\n";
        return 0;
    }
 
    int ans = 0;
 
    // p = 1;
 
    memset(f[1], -1, sizeof f[1]);
    f[1][0][0][0] = 0;
    for (int j = 1; j <= n; ++j) {
        int tk = min(k, j);
 
        if (j <= k) {
            for (int p = 0; p < tk; ++p)
                opt(f[1][j][p][0], f[1][j - 1][p][0]);
            for (int q = 0; q < tk; ++q)
                opt(f[1][j][0][q], f[1][j - 1][0][q]);
        } else {
            for (int p = 0; p < tk; ++p) {
                opt(f[1][j][p][0], f[1][j - 1][p + 1][0]);
                if (p == 0)
                    opt(f[1][j][p][0], f[1][j - 1][0][0]);
            }
            for (int q = 0; q < tk; ++q) {
                opt(f[1][j][0][q], f[1][j - 1][0][q + 1]);
                if (q == 0)
                    opt(f[1][j][0][q], f[1][j - 1][0][0]);
            }
        }
 
        f[1][j][tk][0] = s[j][0] - s[j - tk][0];
        f[1][j][0][tk] = s[j][1] - s[j - tk][1];
    }

    for (int p = 0; p <= k; ++p)
        for (int q = 0; q <= k; ++ q)
            opt(ans, f[1][n][p][q]);
 
    for (int i = 2; i <= x; ++i) {
        memset(f[i % 3], -1, sizeof f[i % 3]);
 
        for (int j = 1; j <= n; ++j) {
            int tk = min(k, j);
 
            // do not cheat
            if (j <= k) {
                for (int p = 0; p < tk; ++p)
                    for (int q = 0; q < tk; ++q)
                        f[i % 3][j][p][q] = f[i % 3][j - 1][p][q];
            } else {
                for (int p = 0; p < tk; ++p)
                    for (int q = 0; q < tk; ++q) {
                        if (f[i % 3][j - 1][p + 1][q + 1] >= 0)
                            opt(f[i % 3][j][p][q], f[i % 3][j - 1][p + 1][q + 1]);
                        // opt(f[i % 3][j][p][q], f[(i - 1) % 3][j][p][q]);
                        if (p == 0)
                            opt(f[i % 3][j][p][q], f[i % 3][j - 1][p][q + 1]);
                        if (q == 0)
                            opt(f[i % 3][j][p][q], f[i % 3][j - 1][p + 1][q]);
                        if (p == 0 && q == 0)
                            opt(f[i % 3][j][p][q], f[i % 3][j - 1][p][q]);
                    }
            }
 
            // cheat with first guy
            for (int q = 0; q <= tk; ++q) {
                int tmp = s[j][0] - s[j - tk][0] - (s[max(j - tk, j - tk + q - 1)][3] - s[j - tk][3]);

                if (f[(i - 1) % 3][j - 1][0][q] >= 0) {
                    int tmp1 = tmp + f[(i - 1) % 3][j - 1][0][max(0, q - (j <= k))];
                    opt(f[i % 3][j][tk][max(q - 1, 0)], tmp1);
                }

                if (j > k && f[(i - 1) % 3][j - 1][1][q] >= 0) {
                    int tmp1 = tmp + f[(i - 1) % 3][j - 1][1][q];
                    opt(f[i % 3][j][tk][max(q - 1, 0)], tmp1);
                }
            }
 
            // cheat with second guy
            for (int p = 0; p <= tk; ++p) {
                int tmp = s[j][1] - s[j - tk][1] - (s[max(j - tk, j - tk + p - 1)][3] - s[j - tk][3]);

                if (f[(i - 1) % 3][j - 1][p][0] >= 0) {
                    int tmp1 = tmp + f[(i - 1) % 3][j - 1][max(0, p - (j <= k))][0];
                    opt(f[i % 3][j][max(p - 1, 0)][tk], tmp1);
                }

                if (j > k && f[(i - 1) % 3][j - 1][p][1] >= 0) {
                    int tmp1 = tmp + f[(i - 1) % 3][j - 1][p][1];
                    opt(f[i % 3][j][max(p - 1, 0)][tk], tmp1);
                }
            }
 
            // cheat with both guy
            if (j <= k) {
                f[i % 3][j][tk][tk] = 0;
            } else {
                for (int p = 0; p < 2; ++p)
                    for (int q = 0; q < 2; ++q)
                        opt(f[i % 3][j][tk][tk], f[(i + 1) % 3][j - 1][p][q]);
            }
            if (f[i % 3][j][tk][tk] >= 0)
                f[i % 3][j][tk][tk] += s[j][2] - s[j - tk][2];
        }
 
        for (int p = 0; p <= k; ++p)
            for (int q = 0; q <= k; ++q)
                opt(ans, f[i % 3][n][p][q]);
    }
 
    // cout << "\n";
 
    cout << ans << "\n";
 
    return 0;
}
