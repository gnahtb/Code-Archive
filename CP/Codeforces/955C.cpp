#include <bits/stdc++.h>

using namespace std;

#define sqr(a) (a) * (a)
#define cub(a) (a) * (a) * (a)

typedef long long ll;

const ll limit = 1E18;

ll Q, L, R;
vector<ll> a;

bool isPerfectSquare(ll x)
{
    ll t = sqrt(x);
    if (sqr(t) == x) return true;
    if (sqr(t + 1) == x) return true;
    return false;
}

void prep()
{
    a.push_back(0);
    for (ll i = 2; i <= 1E6; ++i)
        for (ll j = cub(i); j <= limit; j *= i)
        {
            if (!isPerfectSquare(j)) a.push_back(j);
            if (i > limit / j) break;
        }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    prep();
    scanf("%lld", &Q);
    while (Q--)
    {
        scanf("%lld%lld", &L, &R);
        ll ans = upper_bound(a.begin(), a.end(), R) - lower_bound(a.begin(), a.end(), L);
        ll t = sqrt(R);
        if (sqr(t + 1) <= R) ++t;
        ans += t;
        t = sqrt(L - 1);
        if (sqr(t + 1) < L) ++t;
        ans -= t;
        printf("%lld\n", ans);
    }
    return 0;
}
