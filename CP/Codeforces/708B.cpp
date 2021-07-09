#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

ll a00, a01, a10, a11;

ll calc(ll param)
{
    ll x = 1;
    while ((x * (x - 1)) >> 1LL < param) ++x;
    return ((x * (x - 1)) >> 1LL == param) ? x : -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%lld%lld%lld%lld", &a00, &a01, &a10, &a11);
    if (a00 == 0 && a01 == 0 && a10 == 0)
    {
        ll x = calc(a11);
        if (x > 0) for (int i = 0; i < x; ++i) printf("1");
        else printf("Impossible\n");
        return 0;
    }
    if (a01 == 0 && a10 == 0 && a11 == 0)
    {
        ll x = calc(a00);
        if (x > 0) for (int i = 0; i < x; ++i) printf("0");
        else printf("Impossible\n");
        return 0;
    }
    ll x = calc(a00), y = calc(a11);
    if (!x || !y || a01 + a10 != x * y) { printf("Impossible\n"); return 0; }
    while(x || y)
        if(x && a01 >= y) printf("0"), --x, a01 -= y;
        else printf("1"), --y, a10 -= x;
    return 0;
}
