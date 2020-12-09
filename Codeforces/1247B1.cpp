#include <bits/stdc++.h>

using namespace std;

const int K = 1e6 + 2, N = 2e5 + 2;

int t;
int n, k, d, cnt[K], a[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        for (int i = 1; i <= n; ++i)
            cnt[a[i]] = 0;
        cin >> n >> k >> d;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int ans = INT_MAX, cur = 0;
        for (int i = 1; i < d; ++i) {
            if (cnt[a[i]] == 0) ++cur;
            ++cnt[a[i]];
        }
        for (int i = d; i <= n; ++i) {
            if (cnt[a[i]] == 0) ++cur;
            ++cnt[a[i]];
            ans = min(ans, cur);
            --cnt[a[i - d + 1]];
            if (cnt[a[i - d + 1]] == 0) --cur;
        }
        cout << ans << "\n";
    }
    return 0;
}
