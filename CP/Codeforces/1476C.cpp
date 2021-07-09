#include <bits/stdc++.h>

using namespace std;

const int N = 10 + 2;

int t, n;
long long c[N], a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    freopen("inp.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> c[i];
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        long long ans = 0;
        for (int l = 1, r = 1; l < n; l = r) {
            r = l + 1;
            while (r < n && a[r + 1] != b[r + 1]) ++r;
            long long temp_max = c[r] - 1;
            for (int i = r - 1; i >= l; --i) {
                temp_max += 2;
                long long temp = temp_max + abs(a[i + 1] - b[i + 1]);
                ans = max(ans, temp);
                temp_max += c[i] - 1 - abs(a[i + 1] - b[i + 1]);
                temp_max = max(temp_max, c[i] - 1);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}