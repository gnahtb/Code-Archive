#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;
const long long MOD = 1e9 + 7;

int test, n, a[N], cnt[33];

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> test;
    while (test--) {
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            for (int j = 0; j < 31; ++j)
                cnt[j] += a[i] >> j & 1;
        }
        int target = 0;
        for (int i = 0; i < 31; ++i) target += (cnt[i] == n) << i;
        long long cnt1 = 0;
        for (int i = 1; i <= n; ++i) if (a[i] == target) ++cnt1;
        long long ans = 1;
        for (int i = 1; i <= n - 2; ++i) (ans *= i) %= MOD;
        ans = ans * cnt1 % MOD * (cnt1 - 1) % MOD;
        cout << ans << "\n";
    }
    return 0;
}