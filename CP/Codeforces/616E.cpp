#include <cstdio>
#include <iostream>

using namespace std;

#define sqr(a) (a) * (a)

typedef long long ll;

const ll mod = 1E9 + 7;

ll n, m, ans = 0, tmp;

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%lld%lld", &n, &m);
    ans = m % mod * (n % mod) % mod;
    for (ll i = 1; sqr(i) <= n; ++i)
    {
        ll L = n / (i + 1) + 1, R = min(m, n / i);
        if (L <= R)
        {
            ll sum = (L + R) % mod * ((R - L + 1) % mod) % mod * i % mod * 500000004 % mod;
            ans = (ans - sum + mod) % mod;
        }
        tmp = L;
    }
    for (ll i = 1; i < min(m + 1, tmp); ++i) ans = (ans - (n / i) * i % mod + mod) % mod;
    printf("%lld\n", ans);
    return 0;
}
