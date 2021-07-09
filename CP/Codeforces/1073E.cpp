#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(a) (int)a.size()

struct TData { ll cnt = 0, sum = 0; };

const int CHR_MAX = 10;
const int LEN_MAX = 20;
const ll MOD = 998244353;

ll pw10[LEN_MAX];
TData f[LEN_MAX][1 << CHR_MAX];

inline int getbit(int s, int i) { return s >> i & 1; }

void add(TData &a, TData b, int l, ll d) {
    (a.cnt += b.cnt) %= MOD;
    (a.sum += b.sum + b.cnt * (d * pw10[l - 1] % MOD) % MOD) %= MOD;
}

void prep() {
    pw10[0] = 1;
    f[0][0] = {1, 0};
    for (int l = 1; l < LEN_MAX; ++l) {
        pw10[l] = pw10[l - 1] * 10 % MOD;
        for (int m = 0; m < 1 << CHR_MAX; ++m)
            for (int i = 0; i < CHR_MAX; ++i) if (getbit(m, i)) {
                add(f[l][m], f[l - 1][m], l, i);
                add(f[l][m], f[l - 1][m ^ 1 << i], l, i);
            }
    }
}

ll calc(string x, int k) {
    TData ans;
    for (int l = 1; l < sz(x); ++l)
        for (int i = 1; i < CHR_MAX; ++i)
            for (int m = 0; m < 1 << CHR_MAX; ++m)
                if (__builtin_popcount(m | 1 << i) <= k) {
                    add(ans, f[l - 1][m], l, i);
                }
    for (int i = 0, cur = 0; i < sz(x); cur |= 1 << (x[i++] - '0')) {
        int l = sz(x) - i - 1;
        ll pre = 0;
        for (int j = 0; j < i; ++j) ((pre *= 10) += x[j] - '0') %= MOD;
        for (int d = i == 0; d < x[i] - '0'; ++d)
            for (int m = 0; m < 1 << CHR_MAX; ++m) {
                int t = cur | (1 << d) | m;
                if (__builtin_popcount(t) <= k)
                    add(ans, f[l][m], l + 1, (pre * 10 + d) % MOD);
            }
    }
    return ans.sum;
}

int main() {
    string l, r;
    int k;
    ios_base::sync_with_stdio(false);
    cin >> l >> r >> k;
    prep();
    ll ans = (calc(r, k) - calc(l, k) + MOD) % MOD;
    int cur = 0;
    for (int i = 0; i < sz(r); ++i) cur |= 1 << (r[i] - '0');
    if (__builtin_popcount(cur) <= k)
        for (int i = 0; i < sz(r); ++i)
            (ans += (r[i] - '0') * pw10[sz(r) - i - 1] % MOD) %= MOD;
    cout << ans << "\n";
    return 0;
}
