#include <bits/stdc++.h>

using namespace std;

#define sqr(a) (a) * (a)
#define sz(a) int(a.size())

typedef long long ll;

const int maxK = 2E6 + 5;
const ll mod = 1E9 + 7;

int n, k, p[maxK], cnt[maxK];
bool g[maxK];
ll pw[maxK], ans = 0;

ll power(ll a, ll b)
{
    if (!b) return 1;
    ll tmp = power(a, b >> 1LL), res = sqr(tmp) % mod;
    if ((b & 1)) (res *= a) %= mod;
    return res;
}

void sieve()
{
    memset(p, 0, sizeof p);
    for (int i = 2; i <= k; ++i) p[i] = i;
    for (int i = 2; sqr(i) <= k; ++i) if (p[i] == i)
        for (int j = sqr(i); j <= k; j += i) p[j] = i;
}

vector<int> fact(int x)
{
    vector<int> u;
    while (x > 1)
    {
        int d = p[x];
        while (!(x % d)) x /= d;
        u.push_back(d);
    }
    return u;
}

void solve()
{
    ll s0 = 0, s1 = 0;
    memset(cnt, 0, sizeof cnt);
    memset(pw, 0, sizeof pw);
    memset(g, false, sizeof g);
    for (int i = 1; i <= k; ++i) pw[i] = power(i, n);
    for (int i = 1; i <= k; ++i)
    {
        vector<int> u = fact(i), d;
        g[i] = sz(u) & 1;
        d.push_back(1);
        for (int x: u) for (int i = 0; d[i] % x; ++i) d.push_back(d[i] * x);
        for (int x: d)
            if (g[x]) ((s1 -= pw[cnt[x]]) += pw[++cnt[x]] + mod) %= mod;
            else ((s0 -= pw[cnt[x]]) += pw[++cnt[x]] + mod) %= mod;
        ll tmp = (s0 - s1 + mod) % mod;
        (ans += tmp ^ ll(i)) %= mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    sieve();
    solve();
    cout << ans << "\n";
    return 0;
}
