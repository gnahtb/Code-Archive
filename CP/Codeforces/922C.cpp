#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

ll n, k;
bool c[70];

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%lld%lld", &n, &k);
    if (k > 70) { printf("no\n"); return 0; }
    memset(c, false, sizeof c);
    for (ll i = 1; i <= k; ++i)
    {
        if (c[n % i]) { printf("no\n"); return 0; }
        c[n % i] = true;
    }
    printf("yes\n");
    return 0;
}
