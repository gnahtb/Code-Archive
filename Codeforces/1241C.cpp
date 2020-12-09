#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 2;

int q, n;
ll p[N], k, x, a, y, b;
int o[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> p[i];
        cin >> x >> a >> y >> b >> k;
        sort(p + 1, p + n + 1, greater<ll>());
        for (int i = 1; i <= n; ++i) p[i] += p[i - 1];
        for (int i = 1; i <= n; ++i)
            if (i % a == 0 && i % b == 0) o[i] = 3;
            else if (i % a == 0 || i % b == 0) {
                if (i % a == 0) o[i] = (x > y ? 2 : 1);
                else o[i] = (x < y ? 2 : 1);
            } else o[i] = 0;
        int l = 1, r = n, ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            int cnt3 = 0, cnt2 = 0, cnt1 = 0;
            ll sum = 0;
            for (int i = 1; i <= m; ++i)
                if (o[i] == 3) ++cnt3;
                else if (o[i] == 2) ++cnt2;
                else if (o[i] == 1) ++cnt1;
            sum += (p[cnt3] - p[0]) * (x + y) / 100;
            sum += (p[cnt2 + cnt3] - p[cnt3]) * max(x, y) / 100;
            sum += (p[cnt1 + cnt2 + cnt3] - p[cnt2 + cnt3]) * min(x, y) / 100;
            if (sum >= k) {
                ans = m;
                r = m - 1;
            } else l = m + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
