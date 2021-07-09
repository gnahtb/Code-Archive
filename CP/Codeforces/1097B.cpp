#include <bits/stdc++.h>

using namespace std;

const int MOD = 360;

inline int bit(int b, int i) {
    return b >> i & 1;
}

int n, a[20];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int m = 0; m < 1 << n; ++m) {
        int cur = 0;
        for (int i = 0; i < n; ++i)
            if (bit(m, i)) (cur += a[i]) %= MOD;
            else (cur += MOD - a[i]) %= MOD;
        if (cur == 0) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
