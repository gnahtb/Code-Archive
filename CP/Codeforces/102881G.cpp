#include <bits/stdc++.h>

using namespace std;

int test;

int main() {
    ios::sync_with_stdio(false);
    freopen("gcd.in", "r", stdin);
    cin >> test;
    long long ans = 0;
    while (test--) {
        long long l, r;
        cin >> l >> r;
        if (l < r) ans = 1;
        else ans = __gcd(ans, l);
        cout << ans << "\n";
    }
    return 0;
}