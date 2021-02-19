#include <bits/stdc++.h>

using namespace std;

const int N = 1002;

int t, n, x[N], y[N];

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> x[i] >> y[i];
        }
        sort(x + 1, x + n + 1);
        sort(y + 1, y + n + 1);
        long long ans = 1;
        if (n % 2 == 0) {
            int m1 = (n + 1) / 2;
            int m2 = m1 + 1;
            ans = 1LL * (x[m2] - x[m1] + 1) * (y[m2] - y[m1] + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}