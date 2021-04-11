#include <bits/stdc++.h>

using namespace std;

const int N = 501;

int t, n, l, r, s, ans[N];

int main() {
    cin >> t;
    while (t--) {
        memset(ans, 0, sizeof(ans));
        cin >> n >> l >> r >> s;
        int d = r - l + 1;
        if (d * (d + 1) / 2 <= s && s <= (n - d + 1 + n) * d / 2) {
            for (int i = l; i <= r; ++i) {
                ans[i] = i - l + 1;
                s -= i - l + 1;
            }
            int i = r, cap = n;
            while (s > 0 && i >= l) {
                int tmp = min(cap - ans[i], s);
                ans[i] += tmp;
                --cap;
                --i;
                s -= tmp;
            }
            for (int i = 1; i <= n; ++i) {
                bool app = false;
                for (int j = 1; j <= n; ++j) if (ans[j] == i) {
                    app = true;
                    break;
                }
                if (!app) {
                    for (int j = 1; j <= n; ++j) if (ans[j] == 0) {
                        ans[j] = i;
                        break;
                    }
                }
            }
            for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}