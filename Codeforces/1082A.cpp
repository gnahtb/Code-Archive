#include <bits/stdc++.h>

using namespace std;

long long t, n, x, y, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> x >> y >> d;
        long long z = y % d;
        if (z != x % d && z != 1 && z != n % d) {
            cout << "-1\n";
            continue;
        }
        long long ans = INT_MAX;
        if (z == x % d)
            ans = min(ans, abs(x - y) / d);
        if (z == 1)
            ans = min(ans, (x - 1) / d + ((x - 1) % d > 0) + (y - 1) / d);
        if (z == n % d)
            ans = min(ans, (n - x) / d + ((n - x) % d > 0) + (n - y) / d);
        cout << ans << "\n";
    }
    return 0;
}
