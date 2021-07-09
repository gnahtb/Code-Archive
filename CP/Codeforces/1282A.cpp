#include <bits/stdc++.h>

using namespace std;

int t, a, b, c, r;

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> r;
        int l1 = min(a, b), r1 = max(a, b);
        int l2 = c - r, r2 = c + r;
        int l3 = max(l1, l2), r3 = min(r1, r2);
        if (l3 > r3) l3 = r3 = 0;
        int ans = r1 - l1 - (r3 - l3);
        cout << ans << "\n";
    }
    return 0;
}
