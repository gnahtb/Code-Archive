#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int n, m, a[N], b[N], ans = INT_MAX;

int bs(int x, int *arr, int arrsize) {
    int l = 1, r = arrsize, ret = -1;
    while (l <= r) {
        int mi = (l + r) / 2;
        if (x <= *(arr + mi)) {
            ret = *(arr + mi);
            r = mi - 1;
        } else {
            l = mi + 1;
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; ++i) {
        int x = bs(a[i], b, m);
        if (x > 0) ans = min(ans, x - a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        int x = bs(b[i], a, n);
        if (x > 0) ans = min(ans, x - b[i]);
    }
    cout << ans;
    return 0;
}