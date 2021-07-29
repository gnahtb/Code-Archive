#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int test, n, a[N];

int main() {
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        long long ans = 0;
        for (int i = 1; i < n; ++i) {
            long long tmp = 1LL * min(a[i], a[i + 1]) * max(a[i], a[i + 1]);
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}