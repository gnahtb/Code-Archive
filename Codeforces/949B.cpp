#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

ll n, q;

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%lld%lld", &n, &q);
    while (q--)
    {
        ll x;
        scanf("%lld", &x);
        while (x % 2 == 0) x += n - x / 2;
        printf("%lld\n", (x + 1) / 2);
    }
    return 0;
}

