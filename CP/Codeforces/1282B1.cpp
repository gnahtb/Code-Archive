#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int test;
int n, p, k, a[N], f[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> test;
    while (test--) {
        cin >> n >> p >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + a[i];
            if (i >= k) {
                f[i] = min(f[i], f[i - k] + a[i]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (f[i] > 0 && f[i] <= p) ans = i;
        cout << ans << "\n";
    }
    return 0;
}
