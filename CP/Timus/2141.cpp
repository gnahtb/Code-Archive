#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n;
long long a[N], s[N], ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = n; i; --i) {
        if (i % 2 == 0) s[i] = s[i + 1] + a[i];
        else s[i] = s[i + 1] - a[i];
    }
    long long tmin = 0, tmax = 0;
    for (int i = n; i; --i) {
        if (i % 2 == 0) {
            ans = max(ans, s[i] - tmin);
        } else {
            ans = max(ans, -s[i] + tmax);
        }
        tmin = min(tmin, s[i]);
        tmax = max(tmax, s[i]);
    }
    cout << ans << "\n";
    return 0;
}