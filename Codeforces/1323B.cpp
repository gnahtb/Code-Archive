#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 40002;

int n, m, k, a[N], b[N];
ll cnta[N], cntb[N], ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    for (int l = 1, r = 1; l <= n; l = r) {
        while (r <= n && a[l] == a[r]) ++r;
        if (a[l] == 0) continue;
        for (int i = 1; i <= r - l; ++i)
            cnta[i] += r - l - i + 1;
    }
    for (int l = 1, r = 1; l <= m; l = r) {
        while (r <= m && b[l] == b[r]) ++r;
        if (b[l] == 0) continue;
        for (int i = 1; i <= r - l; ++i)
            cntb[i] += r - l - i + 1;
    }
    for (int i = 1; i <= n; ++i)
        if (k % i == 0 && k / i <= m) {
            ans += cnta[i] * cntb[k / i];
        }
    cout << ans << "\n";
    return 0;
}
