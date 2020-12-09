#include <bits/stdc++.h>

using namespace std;

const int N = 30002, K = 202;
const int oo = 0x3f3f3f;

int n, k, a[N], f[N][K][3][3][2];

void Opt(int& x, int y) {
    if (x < y) x = y;
}

int id(int x) { return x + 1; }

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    memset(f, -oo, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        for (int y = -1; y <= 1; ++y) {
            for (int t = 0; t < 2; ++t) {
                f[i][1][id(0)][id(y)][t] = a[i] * y;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    for (int t = 0; t < 2; ++t) {
                        if (f[i][j][id(x)][id(y)][t] <= -oo) continue;
                        if (t == 0) {
                            // open new interval
                            for (int z = -1; z <= 1; ++z) {
                                if (z == 0 && j + 1 != k) continue;
                                Opt(f[i + 1][j + 1][id(-y)][id(z)][1], f[i][j][id(x)][id(y)][0] + a[i + 1] * (z - y));
                            }

                            // remain
                            Opt(f[i + 1][j][id(x)][id(y)][0], f[i][j][id(x)][id(y)][0]);
                        } else {
                            // add to current interval
                            Opt(f[i + 1][j][id(x)][id(y)][1], f[i][j][id(x)][id(y)][1] + a[i + 1] * (x + y));

                            // open new interval
                            for (int z = -1; z <= 1; ++z) {
                                if (z == 0 && j + 1 != k) continue;
                                Opt(f[i + 1][j + 1][id(-y)][id(z)][1], f[i][j][id(x)][id(y)][1] + a[i + 1] * (z - y));
                            }

                            // close interval
                            Opt(f[i + 1][j][id(x)][id(y)][0], f[i][j][id(x)][id(y)][1]);
                        }
                    }
                }
            }
        }
    }
    int ans = -oo;
    for (int x = -1; x <= 1; ++x) {
        for (int t = 0; t < 2; ++t) {
            Opt(ans, f[n][k][id(x)][id(0)][t]);
        }
    }

    printf("%d\n", ans);

    return 0;
}
