#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> t;
    while (t--) {
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        bool flag = false;
        for (int mask = 0; mask < 16; ++mask) {
            int tu = u, tr = r, td = d, tl = l;
            if (mask & 1) --tl, --tu;
            if (mask >> 1 & 1) --tr, --tu;
            if (mask >> 2 & 1) --tr, --td;
            if (mask >> 3 & 1) --tl, --td;
            if (0 > tu || tu > n - 2) continue;
            if (0 > tr || tr > n - 2) continue;
            if (0 > td || td > n - 2) continue;
            if (0 > tl || tl > n - 2) continue;
            flag = true;
            break;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}