#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int N_MAX = 1e5 + 5;

int n, q, a[N_MAX];
ll pw2[N_MAX], spw2[N_MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        char ch;
        cin >> ch;
        a[i] = a[i - 1] + (int)(ch - '0');
    }
    pw2[0] = spw2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw2[i] = pw2[i - 1] * 2 % MOD;
        spw2[i] = (pw2[i] + spw2[i - 1]) % MOD;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int cnt1 = a[r] - a[l - 1], cnt0 = r - l + 1 - cnt1;
        ll ans = spw2[cnt1 - 1] * (spw2[cnt0 - 1] + 1) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
