#include <bits/stdc++.h>

using namespace std;

const int LIM = 200005;

int n, a[102];
bool flag[2][LIM];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    while (true) {
        bool odd = false;
        for (int i = 1; i <= n; ++i) if (a[i] % 2 != 0) odd = true;
        if (odd) break;
        for (int i = 1; i <= n; ++i) a[i] /= 2;
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += a[i];
    memset(flag, 0, sizeof(flag));
    flag[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 200000; ++j) flag[i & 1][j] = flag[(i - 1) & 1][j];
        for (int j = a[i]; j <= 200000; ++j) flag[i & 1][j] |= flag[(i - 1) & 1][j - a[i]];
    }
    if (sum % 2 != 0 || !flag[n & 1][sum / 2]) {
        cout << "0\n";
    } else {
        cout << "1\n";
        for (int i = 1; i <= n; ++i)
            if (a[i] % 2 != 0) {
                cout << i << "\n";
                break;
            }
    }
    return 0;
}