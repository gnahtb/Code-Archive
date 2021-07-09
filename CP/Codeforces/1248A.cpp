#include <bits/stdc++.h>

using namespace std;

int t, cnt[2][2];

int main() {
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof cnt);
        int n;
        for (int j = 0; j < 2; ++j) {
            cin >> n;
            for (int i = 1, p; i <= n; ++i) {
                cin >> p;
                ++cnt[j][p % 2];
            }
        }
        long long ans = 1LL * cnt[0][0] * cnt[1][0] + 1LL * cnt[0][1] * cnt[1][1];
        cout << ans << "\n";
    }
    return 0;
}
