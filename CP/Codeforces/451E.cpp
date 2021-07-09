#include <bits/stdc++.h>

using namespace std;

#define odd(a) ((a) & 1)
#define sqr(a) (a) * (a)

typedef long long ll;

const int maxN = 25;
const ll mod = 1E9 + 7;

ll n, s, f[maxN], fi[maxN], ans = 0;

ll power(ll a, ll b)
{
    if (!b) return 1;
    ll tmp = power(a, b >> 1LL), ret = sqr(tmp) % mod;
    if (odd(b)) (ret *= a) %= mod;
    return ret;
}

void prep()
{
    memset(fi, 0, sizeof fi);
    fi[0] = 1;
    for (ll i = 1; i <= n; ++i)
        fi[i] = fi[i - 1] * power(i, mod - 2) % mod;
}

int getBit(int bitmask, int id) { return (bitmask >> id) & 1; }

ll nCr(ll n, ll r)
{
    ll ret = fi[r];
    for (ll i = n; i > n - r; --i) (ret *= i % mod) %= mod;
    return ret;
}

void solve()
{
    ll cnt, tmp = 0;
    for (int i = 0; i < n; ++i) tmp += f[i];
    if (tmp < s) return;
    for (int bitmask = 0; bitmask < 1 << n; ++bitmask)
    {
        cnt = 0; tmp = s;
        for (int i = 0; i < n; ++i)
            if (getBit(bitmask, i)) tmp -= f[i] + 1, ++cnt;
        if (tmp < 0) continue;
        (ans += (odd(cnt) ? -1 : 1) * nCr(tmp + n - 1, n - 1) + mod) %= mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (ll i = 0; i < n; ++i) cin >> f[i];
    prep();
    solve();
    cout << ans << "\n";
    return 0;
}
