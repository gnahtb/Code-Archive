#include <bits/stdc++.h>

using namespace std;

const int N = 1002;

int t, n;
char c[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> c[i];
        for (int i = 1; i <= n; ++i) {
            if (c[i] == '1') {
                int tmp = max(i, n - i + 1) * 2;
                ans = max(ans, tmp);
            } else {
                ans = max(ans, max(i, n - i + 1));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
