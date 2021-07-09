#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n;
long long a[N], ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
    if (n % 2 == 0) {
        ans = a[n / 2] * a[n / 2] + (a[n] - a[n / 2]) * (a[n] - a[n / 2]);
    } else {
        ans = a[n / 2] * a[n / 2] + (a[n] - a[n / 2]) * (a[n] - a[n / 2]);
        ans = max(ans, a[n / 2 + 1] * a[n / 2 + 1] + (a[n] - a[n / 2 + 1]) * (a[n] - a[n / 2 + 1]));
    }
    cout << ans << "\n";
    return 0;
}
