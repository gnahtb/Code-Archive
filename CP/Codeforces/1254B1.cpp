#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n, a[N], f[N], t[N], f1[2];

int main() {
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            ++cnt;
            t[cnt] = i;
        }
    }
    long long ans = LLONG_MAX;
    for (int i = 2; i <= cnt; ++i)
        if (cnt % i == 0) {
            long long tmp = 0;
            for (int l = 1, r = i; l <= cnt; l += i, r += i) {
                int m = (l + r) / 2;
                for (int j = l; j <= r; ++j) {
                    tmp += 1LL * abs(t[j] - t[m]);
                }
            }
            ans = min(ans, tmp);
        }
    if (ans == LLONG_MAX) ans = -1;
    cout << ans << "\n";
    return 0;
}
