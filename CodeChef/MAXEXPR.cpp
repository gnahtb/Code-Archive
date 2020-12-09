#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int t;
int n;
double k[N], c[N], x[N];

void solve() {
    double sum = 0, tmp = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        sum -= c[i] * k[i];
        tmp += 1.0 / k[i];
    }
    if (sum > 0.0) {
        cout << "-1";
        return;
    }
    tmp = -sum / tmp;
    for (int i = 1; i <= n; ++i) {
        x[i] = tmp / k[i] / k[i] - c[i];
        ans += sqrt(x[i] + c[i]);
    }
    cout << ans << " ";
    for (int i = 1; i <= n; ++i) cout << x[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    (cout << fixed).precision(10);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> k[i];
        for (int i = 1; i <= n; ++i) cin >> c[i];
        solve();
        cout << "\n";
    }
    return 0;
}