#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 40;
const ll MOD = 1e9 + 7;

int test;
ll s1, s2, xl, xr;

ll g(ll x, int p0, int p1) {
    if (p0 == p1) return 0;
    // if (p0 > __lg(x) || p1 > __lg(x)) return 0;
    ll ret = 0;
    if (p0 < 0) {
        int rem = 1;
        for (int i = __lg(x); i >= 0; --i) {
            if (x >> i & 1) {
                if (i == p1) {
                    --rem;
                    continue;
                }
                (ret += 1LL << (i - rem)) %= MOD;
            } else {
                if (i == p1) break;
            }
        }
    } else {
        int rem = 2;
        for (int i = __lg(x); i >= 0; --i) {
            if (x >> i & 1) {
                if (i == p1) {
                    --rem;
                    continue;
                }
                int tmp = i - rem + (i == p0);
                (ret += 1LL << tmp) %= MOD;
                if (i == p0) break;
            } else {
                if (i == p0) --rem;
                if (i == p1) break;
            }
        }
    }
    return ret;
}

ll f(ll x, ll s1, ll s2) {
    int ls1 = __lg(s1), ls2 = __lg(s2);
    // if (ls2 - ls1 >= __lg(x)) {
    //     ll ts = (x + 1) * x / 2;
    //     return (ts << ls1) % MOD
    // }
    ll ret = 0;
    for (int i = ls2 + __lg(x); i >= ls1; --i) {
        if (i >= ls2) {
            if (i > ls1 + __lg(x)) {
                (ret += (1LL << i) % MOD * g(x, -1, i - ls2) % MOD) %= MOD;
            } else {
                // p1 >= p2
                int p2 = i - ls2, p1 = i - ls1;
                // bit p2 = 0, bit p1 = 1
                ll cnt = g(x, p2, p1);
                // bit p2 = 1, bit p1 = 0
                (cnt += g(x, p1, p2)) %= MOD;
                (ret += (1LL << i) % MOD * cnt % MOD) %= MOD;
            }
        } else {
            if (i <= __lg(x) + ls1)
                (ret += (1LL << i) % MOD * g(x, -1, i - ls1) % MOD) %= MOD;
        }
    }
    return ret;
}

int main() {
#ifdef ONLINE_JUDGE
    freopen("geometry.in", "r", stdin);
#endif
    cin >> test;
    while (test--) {
        cin >> s1 >> s2 >> xl >> xr;
        if (s1 > s2) swap(s1, s2);
        ll fl = f(xl, s1, s2);
        ll fr = f(xr + 1, s1, s2);
        ll ans = (fr - fl + MOD) % MOD;
        // cout << fl << "\n";
        // cout << fr << "\n";
        cout << ans << "\n";
    }
    return 0;
}