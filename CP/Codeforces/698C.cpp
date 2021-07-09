#include <bits/stdc++.h>

using namespace std;
using ld = long double;

inline bool bit(int m, int i) {
    return m >> i & 1;
}

int n, k;
vector<ld> f, p;

int main() {
    cin >> n >> k;
    p.assign(n, 0);
    int k1 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] > 0.0) ++k1;
    }
    f.assign(1 << n, 0);
    f[0] = 1.0;
    for (int m = 1; m < 1 << n; ++m) {
        if (__builtin_popcount(m) > k) continue;
        ld totp = 0;
        for (int i = 0; i < n; ++i)
            if (bit(m, i)) totp += p[i];
        for (int i = 0; i < n; ++i)
            if (p[i] > 0.0 && bit(m, i)) {
                ld temp = 1.0 - totp + p[i];
                f[m] += f[m ^ (1 << i)] * p[i] / temp + 0.0;
            }
    }
    (cout << fixed).precision(10);
    for (int i = 0; i < n; ++i) {
        ld totp = 0;
        for (int m = 1; m < 1 << n; ++m) {
            if (bit(m, i) && __builtin_popcount(m) == min(k, k1)) {
                totp += f[m];
            }
        }
        cout << totp << " ";
    }
    return 0;
}