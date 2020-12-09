#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 2;
const ll MOD = 1e9 + 7;

int n, a[N];
ll k, l[N], r[N], ans;
vector<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = a[n + 1] = INT_MAX;
    s.clear();
    s.push_back(0);
    for (int i = 1; i <= n; ++i) {
        while (a[s.back()] < a[i]) s.pop_back();
        l[i] = s.back();
        s.push_back(i);
    }
    s.clear();
    s.push_back(n + 1);
    for (int i = n; i; --i) {
        while (a[s.back()] <= a[i]) s.pop_back();
        r[i] = s.back();
        s.push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        ll cnt = 0;
        ll d1 = (i - l[i] - 1) / (k - 1) + ((i - l[i] - 1) % (k - 1) > 0);
        ll d2 = (r[i] - i - 1) / (k - 1);
        ll p1 = i, p2 = r[i];
        if (d1 <= d2) {
            p1 = l[i] + 1;
            p2 -= (k - 1) * d1;
            cnt += d1 - 1 + (k - 1) * (d1 - 1) * d1 / 2;
            cnt += i - l[i];
            cnt += (i - l[i]) * (d2 - d1);
            p2 -= (d2 - d1) * (k - 1);
            p2 = max(l[i] + 1, p2 - k + 1);
            cnt += i - l[i];
            cnt -= i - p2 + 1;
        } else {
            cnt += d2 + (k - 1) * d2 * (d2 + 1) / 2;
            p1 -= d2 * (k - 1);
            p2 -= d2 * (k - 1);
            p2 = max(p2 - k + 1, l[i] + 1);
            cnt -= i - p2 + 1;
            p1 = max(p1 - k + 1, l[i] + 1);
            cnt += i - p1 + 1;
            d1 = (p1 - l[i] - 1) / (k - 1);
            cnt += (p2 - p1) * d1;
            p1 -= d1 * (k - 1);
            p2 -= d1 * (k - 1);
            if (p1 > l[i] + 1) {
                cnt += i - l[i];
                p1 = l[i] + 1;
                p2 = max(p2 - k + 1, l[i] + 1);
                cnt -= i - p2 + 1;
            }
        }
        d2 = (p2 - l[i] - 1) / (k - 1);
        cnt += (i - l[i] - (i - p2 + 1)) * d2 - (k - 1) * d2 * (d2 + 1) / 2;

        (ans += cnt % MOD * a[i] % MOD) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
