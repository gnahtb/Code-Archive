#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--) {
        long long n, a, b;
        cin >> n >> a >> b;
        long long ans = min(n / 2 * b + n % 2 * a, n * a);
        cout << ans << "\n";
    }
    return 0;
}
