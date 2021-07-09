#include <bits/stdc++.h>

#define sz(a) (int)a.size()
#define sqr(a) ((a) * (a))

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const int N = 1e5;

ll f[N + 2][10], pw[N + 2];
void prep() {
    memset(f, 0, sizeof f);
    pw[0] = 1;
    pw[1] = 10;
    for (int j = 0; j < 10; ++j) f[1][j] = j;
    for (int i = 2; i <= N; ++i) {
        pw[i] = pw[i - 1] * 10 % MOD;
        ll sm = 0;
        for (int j = 0; j < 10; ++j)
            (sm += f[i - 1][j]) %= MOD;
        for (int j = 0; j < 10; ++j) {
            f[i][j] = sm;
            ll tmp = sqr(pw[i - 2]) % MOD * j % MOD;
            (f[i][j] += MOD - tmp) %= MOD;
            tmp = sqr(pw[i - 1]) % MOD * j % MOD;
            (f[i][j] += tmp) %= MOD;
        }
    }
}

ll query(string& s, bool flag) {
    ll ret = 0, cur = 0;
    for (int i = sz(s); i; --i) {
        for (int j = 0; j < s[i - 1] - '0'; ++j) {
            (ret += f[i][j]) %= MOD;
            ll dif = 0;
            if (i < sz(s) && j == s[i] - '0') {
                dif = sqr(pw[i - 1]) % MOD * j % MOD;
            }
            (ret += MOD - dif) %= MOD;
            (ret += cur * pw[i - 1] % MOD) %= MOD;
        }
        if (i == sz(s) || s[i] != s[i - 1])
            (cur += (s[i - 1] - '0') * pw[i - 1] % MOD) %= MOD;
    }
    (ret += cur * flag) %= MOD;
    return ret;
}

int t, nl, nr;
string l, r;

int main() {
    ios::sync_with_stdio(false);
    // freopen("inp.txt", "r", stdin);
    prep();
    cin >> t;
    while (t--) {
        cin >> nl >> l >> nr >> r;
        reverse(l.begin(), l.end());
        reverse(r.begin(), r.end());
        ll sl = query(l, false);
        ll sr = query(r, true);
        ll ans = (sr - sl + MOD) % MOD;
        // cout << sl << " " << sr << " " << ans << endl;
        cout << ans << endl;
    }
    return 0;
}