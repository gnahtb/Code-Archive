#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 2;

int q, n, a[2], b[2];

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while (q--) {
        cin >> n;
        long long f[3] = {0, 0, 0};
        for (int i = 0; i < n; ++i) {
            cin >> a[i % 2] >> b[i % 2];
            if (i) {
                long long g[3] = {LLONG_MAX, LLONG_MAX, LLONG_MAX};
                for (int j = 0; j < 3; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        if (a[(i - 1) % 2] + j != a[i % 2] + k) {
                            g[k] = min(g[k], f[j] + b[i % 2] * k);
                        }
                    }
                }
                memcpy(f, g, sizeof(f));
            } else {
                f[1] = b[0];
                f[2] = b[0] * 2;
            }
        }
        long long ans = min(f[0], min(f[1], f[2]));
        cout << ans << "\n";
    }
    return 0;
}