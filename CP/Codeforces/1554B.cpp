#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int test, n, k, a[N];

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> test;
    while (test--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (n > 100) {
            long long ans = LLONG_MIN;
            for (int j = n - k + 1; j <= n; ++j)
                for (int i = 1; i < n; ++i) {
                    ans = max(ans, 1LL * j * i - 1LL * k * (a[j] | a[i]));
                }
            cout << ans << endl;
        } else {
            long long ans = LLONG_MIN;
            for (int i = 1; i <= n; ++i) {
                for (int j = i + 1; j <= n; ++j) {
                    ans = max(ans, 1LL * i * j - 1LL * k * (a[i] | a[j]));
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}